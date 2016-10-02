class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int sum;
        sum=nums.size();
        if(sum==0)return 0;
        int index;
        index=0;
        for(int i=1;i<sum;i++)
        {
            if(nums[index]!=nums[i])
            {
                index+=1;
                nums[index]=nums[i];
            }
        }
        index+=1;
        return index;
    }
};
