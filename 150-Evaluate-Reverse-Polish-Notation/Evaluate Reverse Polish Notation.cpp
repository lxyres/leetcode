class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> number;
        vector<string> ss={"+","-","*","/"};
        auto i=tokens.begin();
        while(i!=tokens.end())
        {
            if(find(ss.begin(),ss.end(),*i)!=ss.end())
            {
                int s2=number.top();
                number.pop();
                int s1=number.top();
                number.pop();
                switch(distance(ss.begin(),find(ss.begin(),ss.end(),*i)))
                {
                    case 0:
                        number.push(s1+s2);
                        break;
                    case 1:
                        number.push(s1-s2);
                        break;
                    case 2:
                        number.push(s1*s2);
                        break;
                    default:
                        number.push(s1/s2);
                }
                i++;
            }
            else
            {
                number.push(atoi((*i).c_str()));
                i++;
            }
        }
        return number.top();
    }
};
