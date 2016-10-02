class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<bool> si(m,false);
        vector<bool> sj(n,false);
        auto i=matrix.begin();
        auto ii=si.begin();
        while(i<matrix.end())
        {
            auto j=(*i).begin();
            auto jj=sj.begin();
            while(j<(*i).end())
            {
                if(*j==0)
                {
                    *ii=true;
                    *jj=true;
                }
                j++;
                jj++;
            }
            i++;
            ii++;
        }
        i=matrix.begin();
        ii=si.begin();
        while(i<matrix.end())
        {
            if(*ii)
            {
                auto j=(*i).begin();
                while(j<(*i).end())
                {
                    *j=0;
                    j++;
                }
            }
            else
            {
                auto j=(*i).begin();
                auto jj=sj.begin();
                while(j<(*i).end())
                {
                    if(*jj)*j=0;
                    j++;
                    jj++;
                }
            }
            i++;
            ii++;
        }
    }
};
