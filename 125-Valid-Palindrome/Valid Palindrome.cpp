class Solution {
public:
    bool isPalindrome(string s) 
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        auto p=s.begin();
        auto q=s.end()-1;
        while(p<q)
        {
            if(isalnum(*p))
            {
                if(isalnum(*q))
                {
                    if(*p!=*q)return false;
                    else
                    {
                        p++;
                        q--;
                    }
                }
                else
                {
                    q--;
                }
            }
            else
            {
                p++;
            }
        }
        return true;
    }
};
