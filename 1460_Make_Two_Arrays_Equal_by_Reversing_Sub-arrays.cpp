#include<iostream>
#include<vector>

using namespace std;



class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr)
    {
        int t[1001] = { 0 };
        int a[1001] = { 0 };
        size_t tsize = target.size();
        for (int i = 0; i < tsize; ++i)
        {
            ++t[target[i]];
        }
        for (int i = 0; i < tsize; ++i)
        {
            if (t[arr[i]] == 0)
                return false;
            else
                --t[arr[i]];
        }
        return true;
    }
};


int main()
{

    Solution s;
    vector<int> target = { 3,7,9 };
    vector<int> arr = { 3,7,11 };
    cout<<s.canBeEqual(target, arr);
    return 0;
}