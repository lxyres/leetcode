class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        int m=s.length();
        if (m<=2)return s;
        int num=0;
        if(s[0]==s[1])num=2;
        auto save=s.begin();
        auto s1=s.begin();
        auto s2=s1+1;
        auto s3=s2+1;
        while(s3<s.end())
        {
            if(*s2==*s3)
            {
                int tmp=2;
                auto p1=s2-1;
                auto p2=s3+1;
                while(p1>=s.begin() && p2<s.end())
                {
                    if(*p1==*p2)
                    {
                        tmp+=2;
                        p1--;
                        p2++;
                    }
                    else break;
                }
                if (tmp>num)
                {
                    num=tmp;
                    save=p1+1;
                }
            }
            if(*s1==*s3)
            {
                int tmp=3;
                auto p1=s1-1;
                auto p2=s3+1;
                while(p1>=s.begin() && p2<s.end())
                {
                    if(*p1==*p2)
                    {
                        tmp+=2;
                        p1--;
                        p2++;
                    }
                    else break;
                }
                if (tmp>num)
                {
                    num=tmp;
                    save=++p1;
                }
            }
            s1=s2;
            s2=s3;
            s3++;
        }
        return s.substr(distance(s.begin(),save),num);
    }
};
