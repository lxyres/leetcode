class Solution {
public:
    int climbStairs(int n) 
    {
        vector<int> s(n+2,0);
        s[0]=1;
        for(int i=0;i<n;i++)
        {
            s[i+1]+=s[i];
            s[i+2]+=s[i];
        }
        return s[n];
    }
};
