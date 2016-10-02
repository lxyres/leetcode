class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int sum;
        sum=nums.size();
        if(sum==0)return -1;
        //if(sum==1)return -1+(nums[0]==target)?1:0;
        int start=0;
        int end=sum-1;
        int new_end;
        if (nums[start]==target)return start;
        if (nums[end]==target)return end;
        while((end-start)>1)
        {
            new_end=(start+end)/2;
            if(target<nums[start])
            {
                if(nums[start]<nums[end])return -1;
                if(nums[end]<target)return -1;
                if(nums[new_end]==target)return new_end;
                if(nums[new_end]<nums[end])
                {
                    if(nums[new_end]<target)start=new_end;
                    else end=new_end;
                }
                else start=new_end;
            }
            else
            {
                if(nums[new_end]==target)return new_end;
                if(nums[start]<nums[new_end])
                {
                    if(nums[new_end]<target)start=new_end;
                    else end=new_end;
                }
                else end=new_end;
            }
        }
        return -1;
    }
    
};
