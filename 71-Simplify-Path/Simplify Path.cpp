class Solution {
public:
    string simplifyPath(string path) 
    {
        const char *s=path.c_str();
        vector<string> save;
        while(*s!='\0')
        {
            if(*s=='/')
            {
                string tmp;
                s++;
                while(*s!='\0')
                {
                    if(*s=='/')s++;
                    else break;
                }
                if(*s=='.')
                {
                    s++;
                    if(*s=='/')continue;
                    else if(*s=='.')
                    {
                        s++;
                        if(*s=='/')
                        {
                            if(save.size()!=0)save.pop_back();
                            continue;
                        }
                        else if(*s=='\0')
                        {
                            
                            if(save.size()!=0)save.pop_back();
                            break;
                        }
                        else 
                        {
                            tmp+='/';
                            tmp+='.';
                            tmp+='.';
                            tmp+=*s;
                            s++;
                        }
                    }
                    else if(*s=='\0')break;
                    else 
                    {
                        tmp+="/.";
                        tmp+=*s;
                        s++;
                    }
                        
                }
                else if(*s=='\0')break;
                else 
                {
                    tmp+='/';
                    tmp+=*s;
                    s++;
                }
                while(*s!='\0')
                {
                    if(*s=='/')
                    {
                        break;
                    }
                    else 
                    {
                        tmp+=*s;
                        s++;
                    }
                }
                if(tmp.length()!=0)save.push_back(tmp);
            }
            else s++;
        }
        string result;
        if (save.size()==0)result+='/';
        else
        {
            for(auto i=save.begin();i<save.end();i++)
            {
                result+=*i;
            }
        }
        return result;
    }
};
