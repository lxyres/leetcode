class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int m=nums.size();
        if (m<=1)return;
        else if(m==2)
        {
            m=nums[0];
            nums[0]=nums[1];
            nums[1]=m;
            return;
        }
        for(auto i=nums.rbegin();i<nums.rend()-1;i++)
        {
            auto j=i+1;
            if(*j<*i)
            {
                auto k=i;
                auto l=nums.rbegin();
                for (l=nums.rbegin();l!=j;l++)
                {
                    if(*l>*j)
                    {
                        swap(*j,*l);
                        break;
                    }
                }
                l=nums.rbegin();
                while(l<k)
                {
                    swap(*l,*k);
                    l++;
                    k--;
                }
                return;
            }
        }
        auto i=nums.rbegin();
        auto j=nums.rend()-1;
        while(i<j)
        {
            swap(*i,*j);
            i++;
            j--;
        }
        return;
    }
};
