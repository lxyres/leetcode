class Solution {
public:
    bool isMatch(string s, string p) 
    {
        return isMatch(s.c_str(), p.c_str());
    }
private:
    bool isMatch(const char *s,const char *p)
    {
        bool star=false;
        const char *ss=s;
        const char *pp=p;
        while(*ss!='\0')
        {   
            if(*pp==*ss || *pp=='?')
            {
                pp++;
                ss++;
            }
            else if(*pp=='*')
            {
                pp++;
                while(*pp=='*')pp++;
                s=ss;
                p=pp;
                star=true;
            }
            else
            { 
               if(*pp!=*ss)
               {
                   if(star)
                   {
                       s++;
                       pp=p;
                       ss=s;
                   }
                   else return false;
               }
            }
        }
        while(*pp=='*')pp++;
        return *pp=='\0';
    }
};
