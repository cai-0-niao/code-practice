//排序
int X = 0;
vector<int> a;
bool cmp(int x,  int y)
{
	if (abs(x - X) < abs(y - X))
		return true;
	else if (abs(x - X) == abs(y - X) && x < y)
		return true;
	return false;
}

class Solution {
public:
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {
        X=x;
        sort(arr.begin(), arr.end(),cmp);
        sort(arr.begin(), arr.begin() + k);
        return vector<int>(arr.begin(),arr.begin()+k);
    }
};


//二分+双指针
int X = 0;
bool cmp(vector<int>& arr,const int x, const int y)
{
    if (x < 0)
        return false;
    if (y == arr.size())
        return true;
	if (abs(arr[x] - X) < abs(arr[y] - X))
		return true;
	else if (abs(arr[x] - X) == abs(arr[y] - X) && x < y)
		return true;
	return false;
}

int Find(vector<int>& arr,int begin,int end, int x)
{
    int mid = begin + (end - begin) / 2;
    if (end - begin == 1)
        return end;
    if (arr[mid] == x)
        return mid;
    if (arr[mid] > x)
    {
        return Find(arr, begin, mid, x);
    }
    else
        return Find(arr, begin + 1, end, x);
}


class Solution {
public:
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {
        int Size = arr.size();
        vector<int>ans(k, 0);
        X = x;
        int right = Find(arr, 0, Size, x);
        int left = right - 1;
        int index = 0;
        while (index < k)
        {
            if (cmp(arr,left, right))
                ans[index] = arr[left--];
            else
                ans[index] = arr[right++]; 
            index++;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};