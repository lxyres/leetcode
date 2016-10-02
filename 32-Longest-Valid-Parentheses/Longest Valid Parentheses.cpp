class Solution {
public:
    int longestValidParentheses(string s) 
    {
        int len=0;
        stack<int> save;
        unordered_map<int,int> check;
        int i;
        for(i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                save.push(i);
            }
            else
            {
                if(!save.empty())
                {
                   int now=save.top();
                   save.pop();
                   if(check.find(now-1)!=check.end())
                   {
                       len=max(len,i+1-check[now-1]);
                       check[i]=check[now-1];
                   }
                   else
                   {
                       len=max(len,i+1-now);
                       check[i]=now;
                   }
                }
            }
        }
        return len;
    }
};
