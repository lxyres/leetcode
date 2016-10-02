class Solution {
public:
    string addBinary(string a, string b) 
    {
        int m=a.length();
        int n=b.length();
        int tmp;
        if(m==0)return b;
        if(n==0)return a;
        
        if(m<n)
        {
            string s="0";
            s+=b;
            auto p=a.rbegin();
            auto q=s.rbegin();
            while(p<a.rend())
            {
                tmp=(*p-'0')+(*q-'0');
                if(tmp==0)
                {
                    *q='0';
                    p++;
                    q++;
                }
                else if(tmp==1)
                {
                    *q='1';
                    p++;
                    q++;
                }
                else if(tmp==2)
                {
                    *q='0';
                    p++;
                    q++;
                    *q+=1;
                }
                else
                {
                    *q='1';
                    p++;
                    q++;
                    *q+=1;
                }
            }
            while(q<s.rend())
            {
                if(*q=='2')
                {
                    *q='0';
                    q++;
                    *q+=1;
                }
                else break;
            }
            if(s[0]=='0')s=s.erase(0,1);
            return s;
        }
        else
        {
            string s="0";
            s+=a;
            auto p=b.rbegin();
            auto q=s.rbegin();
            while(p<b.rend())
            {
                tmp=(*p-'0')+(*q-'0');
                if(tmp==0)
                {
                    *q='0';
                    p++;
                    q++;
                }
                else if(tmp==1)
                {
                    *q='1';
                    p++;
                    q++;
                }
                else if(tmp==2)
                {
                    *q='0';
                    p++;
                    q++;
                    *q+=1;
                }
                else
                {
                    *q='1';
                    p++;
                    q++;
                    *q+=1;
                }
            }
            while(q<s.rend())
            {
                if(*q=='2')
                {
                    *q='0';
                    q++;
                    *q+=1;
                }
                else break;
            }
            if(s[0]=='0')s=s.erase(0,1);
            return s;
        }
    }
};
