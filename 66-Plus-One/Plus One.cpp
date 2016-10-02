class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        auto i=digits.rbegin();
        *i+=1;
        while(i<digits.rend()-1)
        {
            if(*i<10)break;
            else
            {
                *i=0;
                i++;
                *i+=1;
            }
        }
        if(digits[0]==10)
        {
            digits[0]=0;
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};
