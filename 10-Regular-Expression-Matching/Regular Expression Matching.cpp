class Solution {
public:
    bool isMatch(const string& s, const string& p) 
    {
        return isMatch(s.c_str(), p.c_str());
    }
private:
    bool isMatch(const char *s, const char *p) 
    {
        int star=0;//0 nothing   1 character 2 .
        const char *location_s;
        const char *location_p;
        const char *origin;
        while( *p!='\0' || star>0)
        {
            if(*(p+1)!='*')
            {
                if(*p==*s)
                {
                    if(*p=='\0')return true;
                    p++;
                    s++;
                }
                else if(*p=='.')
                {
                    p++;
                    s++;
                }
                else if(star==1)
                {
                    if(*location_s!=*origin)return false;
                    location_s++;
                    s=location_s;
                    p=location_p;
                    if(s=='\0')break;
                }
                else if(star==2)
                {
                    location_s++;
                    s=location_s;
                    p=location_p;
                    if(s=='\0')break;
                }
                else return false;
            }
            else
            {
                if(*p=='.')
                {
                    star=2;
                    p+=2;
                    location_p=p;
                    location_s=s;
                }
                else if(*p==*s)
                {
                    star=1;
                    origin=s;
                    p+=2;
                    location_p=p;
                    location_s=s;
                }
                else p+=2;
            }
            
        }
        while(*p!='\0')
        {
            if(*(p+1)=='*')p+=2;
            else return false;
        }
        return *s=='\0';
    }
};
