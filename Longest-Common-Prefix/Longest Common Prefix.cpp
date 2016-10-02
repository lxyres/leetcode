class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string s;
        if(strs.size()==0)return s;
        s=strs[0];
        int ss=s.length();
        for(int i=1;i<strs.size();i++)
        {
            ss=min(ss,(int)strs[i].length());
            for(int j=0;j<ss;j++)
            {
                if(s[j]!=strs[i][j])
                {
                    ss=j;
                    break;
                }
            }
        }
        return s.substr(0,ss);
        
    }
};
