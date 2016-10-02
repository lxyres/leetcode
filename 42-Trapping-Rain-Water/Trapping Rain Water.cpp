class Solution {
public:
    int trap(vector<int>& height) 
    {
        int trap=0;
        if (height.size()<3)return 0;
        auto i=height.begin();
        auto j=height.end()-1;
        int left_h=0;
        int right_h=0;
        while(i<=j)
        {
            if(*i>left_h)
            {
                left_h=*i;
                i++;
            }
            else if(*i<left_h)break;
            else i++;
        }
        while(i<=j)
        {
            if(*j>right_h)
            {
                right_h=*j;
                j--;
            }
            else if(*j<right_h)break;
            else j--;
        }
        while(i<=j)
        {
            if(left_h<right_h)
            {
                while(i<=j)
                {
                    if(*i<=left_h)
                    {
                        trap+=left_h-*i;
                        i++;
                    }
                    else
                    {
                        while(i<=j)
                        {
                            if(*i>left_h)
                            {
                                left_h=*i;
                                i++;
                            }
                            else if(*i<left_h)break;
                            else i++;
                        }
                        break;
                    }
                }
            }
            else
            {
                while(i<=j)
                {
                    if(*j<=right_h)
                    {
                        trap+=right_h-*j;
                        j--;
                    }
                    else
                    {
                        while(i<=j)
                        {
                            if(*j>right_h)
                            {
                                right_h=*j;
                                j--;
                            }
                            else if(*j<right_h)break;
                            else j--;
                        }
                        break;
                    }
                }
            }
        }
        return trap;
    }
};
