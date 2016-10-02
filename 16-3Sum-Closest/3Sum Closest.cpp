class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(),nums.end());
        int m=nums.size();
        int result=0;
        int i;
        if (m<=3)
        {
            for(i=0;i<m;i++)result+=nums[i];
            return result;
        }
        int bottum=INT_MIN;
        int top=INT_MAX;
        int tmp;
        for(auto i=nums.begin();i<nums.end()-2;i++)
        {
            auto j=i+1;
            auto k=nums.end()-1;
            while(j<k)
            {
                tmp=*i+*j+*k;
                if(tmp<target)
                {
                    if (tmp>bottum)bottum=tmp;
                    j++;
                }
                else if(tmp>target)
                {
                    if(tmp<top)top=tmp;
                    k--;
                }
                else return target;
            }
        }
        if(bottum==INT_MIN)return top;
        if(top==INT_MAX)return bottum;
        return (abs(top-target)<abs(target-bottum))?top:bottum;


    }
};
