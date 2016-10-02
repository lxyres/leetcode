class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> save;
        const char* ss=s.c_str();
        while(*ss!='\0')
        {
            switch(*ss)
            {
                case '(':
                    save.push('(');
                    ss++;
                    break;
                case '[':
                    save.push('[');
                    ss++;
                    break;
                case '{':
                    save.push('{');
                    ss++;
                    break;
                case ')':
                    if(save.empty())return false;
                    if(save.top()=='(')
                    {
                        save.pop();
                        ss++;
                        break;
                    }
                    else return false;
                case ']':
                    if(save.empty())return false;
                    if(save.top()=='[')
                    {
                        save.pop();
                        ss++;
                        break;
                    }
                    else return false;
                case '}':
                    if(save.empty())return false;
                    if(save.top()=='{')
                    {
                        save.pop();
                        ss++;
                        break;
                    }
                    else return false;
                default:
                    ss++;
            }
        }
        return save.empty();
    }
};
