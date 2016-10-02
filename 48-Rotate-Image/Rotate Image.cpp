class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        int k=n/2;
        int s10,s11,s20,s21,s30,s31;
        int tmp;
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<k;j++)
            {
                tmp=matrix[i][j];
                s10=j;
                s11=n-1-i;
                s20=n-1-i;
                s21=n-1-j;
                s30=n-1-j;
                s31=i;
                matrix[i][j]=matrix[s30][s31];
                matrix[s30][s31]=matrix[s20][s21];
                matrix[s20][s21]=matrix[s10][s11];
                matrix[s10][s11]=tmp;
            }
        }
        if(n%2==1)
        {
            for(int i=0;i<k;i++)
            {
                tmp=matrix[i][k];
                s11=n-1-i;
                s20=n-1-i;
                s31=i;
                matrix[i][k]=matrix[k][s31];
                matrix[k][s31]=matrix[s20][k];
                matrix[s20][k]=matrix[k][s11];
                matrix[k][s11]=tmp;
            }
        }
    }
};
