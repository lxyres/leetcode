class Solution {
public:
    string countAndSay(int n) 
    {
        string s="1";
        n--;
        if (n<=0)return s;
        while(n>0)
        {
            const char *p=s.c_str();
            string s_tep;
            char now=*p;
            int number=1;
            p++;
            while(*p!='\0')
            {
                if(*p==now)
                {
                    number++;
                    p++;
                }
                else
                {
                    s_tep+=('0'+number);
                    s_tep+=now;
                    now=*p;
                    number=1;
                    p++;
                }
            }
            s_tep+=('0'+number);
            s_tep+=now;
            s=s_tep;
            n--;
        }
        return s;
    }
};
