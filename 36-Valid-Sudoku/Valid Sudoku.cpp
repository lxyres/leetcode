class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        int now,heng,shu,fang;
        vector<bool> s1(243);
        for(int i=0;i<243;i++)s1[i]=false;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')continue;
                now=board[i][j]-'1';
                heng=i*9+now;
                shu=j*9+now+81;
                fang=(i/3)*27+(j/3)*9+now+162;
                if(s1[heng]==true)return false;
                else s1[heng]=true;
                if(s1[fang]==true)return false;
                else s1[fang]=true;
                if(s1[shu]==true)return false;
                else s1[shu]=true;
            }
        }
        return true;
        
    }
};
