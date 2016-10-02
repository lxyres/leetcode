class Solution {
public:
    bool isNumber(string s) 
    {
        if(s.length()==0)return false;
        auto ss=s.begin();
        int status=-2;
        while(*ss!='\0')
        {
            if(*ss==' ')ss++;
            else break;
        }
        while(*ss!='\0')
        {
            if(status==-2) // + - . number
            {
                if(isdigit(*ss))
                {
                    ss++;
                    status=1;
                }
                else if(*ss=='-' ||*ss=='+')
                {
                    ss++;
                    status=0;
                }
                else if(*ss=='.')
                {
                    status=2;
                    ss++;
                }
                else return false;
            }
            else if(status==-1) // + - . number
            {
                if(isdigit(*ss))
                {
                    ss++;
                    status=1;
                }
                else if(*ss=='-' )
                {
                    ss++;
                    status=0;
                }
                else if(*ss=='.')
                {
                    status=2;
                    ss++;
                }
                else return false;
            }
            else if(status==0)  //first number
            {
                if(isdigit(*ss))
                {
                    ss++;
                    status=1;
                }
                else if(*ss=='.')
                {
                    ss++;
                    status=2;
                }
                else return false;
            }
            else if(status==1) //second number
            {
                if(isdigit(*ss))ss++;
                else if(*ss=='.')
                {
                    ss++;
                    status=3;
                }
                else if(*ss=='e')
                {
                    ss++;
                    status=4;
                }
                else if(*ss==' ')
                {
                    ss++;
                    while(*ss!='\0')
                    {
                        if(*ss==' ')ss++;
                        else return false;
                    }
                    return true;
                }
                else return false;
            }
            else if(status==2) //dot hou must number
            {
                if(isdigit(*ss))
                {
                    ss++;
                    status=3;
                }
                else return false;
            }
            else if(status==3)// after dot with number or e or nothing
            {
                if(isdigit(*ss))ss++;
                else if(*ss=='e')
                {
                    ss++;
                    status=4;
                }
                else if(*ss==' ')
                {
                    ss++;
                    while(*ss!='\0')
                    {
                        if(*ss==' ')ss++;
                        else return false;
                    }
                    return true;
                }
                else return false;
            }
            else if(status==4)
            {
                if(isdigit(*ss))
                {
                    ss++;
                    status=5;
                }
                else if(*ss=='-' ||*ss=='+')
                {
                    ss++;
                    if(isdigit(*ss))
                    {
                        status=5;
                        ss++;
                    }
                    else return false;
                }
                else return false;
            }
            else if(status==5)
            {
                if(isdigit(*ss))ss++;
                else if(*ss==' ')
                {
                    ss++;
                    while(*ss!='\0')
                    {
                        if(*ss==' ')ss++;
                        else return false;
                    }
                    return true;
                }
                else return false;
            }
        }
        if (status==-2 ||status==-1 || status==0 || status==2 || status==4)return false;
        return true;
    }
};
