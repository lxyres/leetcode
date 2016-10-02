class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int sum;
        sum=nums.size();
        if (sum<=2)return sum;
        int index=1;
        for (int i = 2; i < sum; i++)
        {
            if (nums[i] == nums[index])
            {
                if(nums[index-1]==nums[i])continue;
            }
            nums[++index]=nums[i];
        }
        return index+1;
    }
};
