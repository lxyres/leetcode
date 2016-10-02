class Solution {
public:
    string getPermutation(int n, int k) 
    {
        vector<string> s1={"1","2","3","4","5","6","7","8","9"};
        string s2;
        int m=1;
        k=k-1;
        for(int i=1;i<=n;i++)
        {
            m*=i;
        }
        k=k%m;
        int check;
        for(int i=n;i>0;i--)
        {
            m/=i;
            check=k/m;
            auto now=s1.begin()+check;
            s2+=*now;
            s1.erase(now);
            k=k%m;
        }
        return s2;
        
    }
};
