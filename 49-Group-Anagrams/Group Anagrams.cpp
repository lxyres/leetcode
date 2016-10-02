class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        
        
        vector<vector<string>> sss;
        if (strs.size()==0)return sss;
        unordered_map<string,vector<string>> group;
        auto s=strs.begin();
        while (s!=strs.end())
        {
            string ss=*s;
            sort(ss.begin(),ss.end());
            group[ss].push_back(*s);
            s++;
        }
        auto i=group.begin();
        for(i=group.begin();i!=group.end();i++)
        {
            sss.push_back(i->second);
        }
        return sss;
    }
};
