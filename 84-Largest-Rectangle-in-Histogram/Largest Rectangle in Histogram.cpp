class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int num=heights.size();
        if(num==0)return 0;
        if(num==1)return heights[0];
        int largest=0;
        stack<pair<int,int>> save; //pair location, height
        int status;
        int now_height;
        int now_start;
        int i=1;
        while(i<num && heights[0]==heights[i]) i++;
        if(i==num)return heights[0]*num;
        if(heights[0]<heights[i])
        {
            status=0;
            largest=max(largest,heights[i]);
            save.push(make_pair(0,heights[0]));
            save.push(make_pair(i,heights[i]));
        }
        else
        {
            now_height=heights[i];
            now_start=0;
            largest=max(heights[0]*i,heights[i]*(i+1));
            status=1;
        }
        i++;
        while(i<num)
        {
            if(status==0)
            {
                if(heights[i-1]<heights[i])
                {
                    largest=max(largest,heights[i]);
                    save.push(make_pair(i,heights[i]));
                    i++;
                }
                else if (heights[i-1]==heights[i])
                {
                    i++;
                }
                else
                {
                    status=1;
                    now_height=save.top().second;
                    now_start=save.top().first;
                    save.pop();
                    largest=max(largest,now_height*(i-now_start));
                }
            }
            else 
            {
                if(heights[i-1]>=heights[i])
                {
                    if(!save.empty() && heights[i]<save.top().second)
                    {
                        now_start=save.top().first;
                        now_height=save.top().second;
                        largest=max(largest,now_height*(i-now_start));
                        save.pop();
                    }
                    else if(!save.empty() && heights[i]==save.top().second)
                    {
                        now_height=heights[i];
                        now_start=save.top().first;
                        largest=max(largest,now_height*((++i)-now_start));
                        save.pop();
                    }
                    else
                    {
                        now_height=heights[i];
                        largest=max(largest,now_height*((++i)-now_start));
                    }
                }
                else
                {
                        status=0;
                        save.push(make_pair(now_start,heights[i-1]));
                }
            }
        }
        
        while(!save.empty())
        {
            largest=max(largest,save.top().second*(num-save.top().first));
            save.pop();
        }
        return largest;
    }
};
