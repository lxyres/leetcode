class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int m=haystack.length();
        int n=needle.length();
        if(m<n)return -1;
        if(n==0)return 0;
        for(int i=0;i<1+m-n;i++)
        {
            if(haystack[i]==needle[0])
            {
                if(isStr(haystack.substr(i+1,n-1),needle.substr(1,n-1),n-1))return i;
            }
        }
        return -1;
    }
private:
    bool isStr(string haystack, string needle,int n)
    {
        for(int i=0;i<n;i++)
        {
            if (haystack[i]!=needle[i])return false;
        }
        return true;
    }
};
