class Solution {
public:
    int myAtoi(string str) 
    {
        unordered_map<string,int> s1;
        s1["0"]=0;
        s1["1"]=1;
        s1["2"]=2;
        s1["3"]=3;
        s1["4"]=4;
        s1["5"]=5;
        s1["6"]=6;
        s1["7"]=7;
        s1["8"]=8;
        s1["9"]=9;
        int initial=1;
        int number=0;
        int i=0;
        while(i<str.length())
        {
            if(str[i]==' ')i++;
            else if(str[i]=='-')
            {
                initial=-1;
                i++;
                break;
            }
            else if(str[i]=='+')
            {
                i++;
                break;
            }
            else if(isdigit(str[i]))break;
            else return 0;
        }
        if(initial==1)
        {
            while(i<str.length())
            {
                if(isdigit(str[i]))
                {
                    if(number>INT_MAX/10||(number == INT_MAX / 10 && (str[i]-'0')>INT_MAX%10))return INT_MAX;
                    number=number*10+(str[i]-'0');
                    i++;
                }
                else break;
            }
        }
        else
        {
            while(i<str.length())
            {
                if(isdigit(str[i]))
                {
                    if(number<INT_MIN/10||(number==INT_MIN/10 && ('0'-str[i])<INT_MIN%10))return INT_MIN;
                    number=number*10-(str[i]-'0');
                    i++;
                }
                else break;
            }
        }
        return number;
        
    }
};
