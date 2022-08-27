class Solution {
public:
   
    int maxProduct(vector<int>& nums) 
    {
        int val[2] = {0};
        if (nums[0] < nums[1])
        {  
            val[0]=nums[1];
            val[1]=nums[0];
        }
        else
        {  
            val[0]=nums[0];
            val[1]=nums[1];
        }
        int len = nums.size();
        for (int i = 2; i < len; ++i)
        {
            if (nums[i] > val[0])
            {
                val[1] = val[0];
                val[0] = nums[i];
            }
            else if (nums[i] == val[0] || nums[i] > val[1])
                val[1] = nums[i];
           
        }
        return (val[1] - 1) * (val[0] - 1);
    }
};