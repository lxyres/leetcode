class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<int> s;
        vector<vector<int>> sss;
        int sum;
        if(nums.size()<3)return sss;
        else if(nums.size()==3)
        {
            if(nums[0]+nums[1]+nums[2]==0)sss.push_back(nums);
            return sss;
        }
        s.push_back(nums[0]);
        int i;
        int j;
        int k;
        for(int i=1;i<nums.size();i++)
        {
            k=nums[i];
            int kk=s.size();
            for(j=0;j<kk;j++)
            {
                if(k<=s[j])break;
            }
            if(j==kk)s.push_back(k);
            else s.insert(s.begin()+j,k);
        }
        sum=s.size();
        int s1,s2,s3;
        i=0;
        while(i<=sum-3)
        {
            s1=s[i];
            if(s1>0)break;
            if(i==sum-3)
            {
                s2=s[i+1];
                s3=s[i+2];
                if(s1+s2+s3==0)
                {
                    vector<int> ssss(3);
                    ssss[0]=s1;
                    ssss[1]=s2;
                    ssss[2]=s3;
                    sss.push_back(ssss);
                }
                break;
            }
            s2=s[i+1];
            if(s1==s2)
            {
              s3=s[i+2];
              if(s1==0 && s2==0 &&s3==0)
              {
                    vector<int> ssss(3);
                    ssss[0]=0;
                    ssss[1]=0;
                    ssss[2]=0;
                    sss.push_back(ssss);
              }
              while(s2==s3)
              {
                  i+=1;
                  s3=s[i+2];
              }
              i+=1;
              j=i;
            }
            else
            {
                j=i+1;
            }
            k=j+1;
            while(j<=sum-2)
            {
                s2=s[j];
                s3=0-s1-s2;
                if(s3<s2)break;
                if(s3<s[j+1])break;
                else if(s2 == s3)
                {
                    if(s3==s[j+1])
                    {
                        vector<int> ssss(3);
                        ssss[0]=s1;
                        ssss[1]=s2;
                        ssss[2]=s3;
                        sss.push_back(ssss);
                    }
                    break;
                }
                while(s2==s[j+1])
                {
                    j+=1;
                }
                if(k<=j)k=j+1;
                else if(k>=sum)k=sum-1;
                if(s[k]<=s3)
                {
                    while(k<sum)
                    {
                        if(s[k]==s3)
                        {
                            vector<int> ssss(3);
                            ssss[0]=s1;
                            ssss[1]=s2;
                            ssss[2]=s3;
                            sss.push_back(ssss);
                            break;
                        }
                        else if(s[k]>s3)break;
                        k+=1;
                    }
                }
                else
                {
                    while(k>j)
                    {
                        if(s[k]==s3)
                        {
                            vector<int> ssss(3);
                            ssss[0]=s1;
                            ssss[1]=s2;
                            ssss[2]=s3;
                            sss.push_back(ssss);
                            break;
                        }
                        else if(s[k]<s3)break;
                        k-=1;
                    }
                }
                j++;
            }

            i++;
        }
        return sss;
    }
};
