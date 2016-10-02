class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        auto s1=s.rbegin();
        while(*s1==' ')s1++;
        auto s2=find(s1,s.rend(),' ');
        return distance(s1,s2);
    }
};
