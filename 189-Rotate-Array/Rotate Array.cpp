class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int m=nums.size();
        if(m<2)return;
        int n=m-k%m;
        for(int i=0;i<n;i++)
        {
            nums.insert(nums.end(),*nums.begin());
            nums.erase(nums.begin());
        }
        return;
    }
};
