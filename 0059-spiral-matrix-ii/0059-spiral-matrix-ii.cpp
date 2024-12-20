class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int startrow=0;
        int endrow=n-1;
        int startcol=0;
        int endcol=n-1;
        vector<vector<int>> mat(n,vector<int>(n,0));
        int v=1;
        while(startrow<=endrow && startcol<=endcol){
        
            for(int i=startcol;i<=endcol;i++){
                mat[startrow][i]=v;v++;
            }
            startrow+=1;
            for(int x=startrow;x<=endrow;x++){
                mat[x][endcol]=v;v++;
            }
            endcol--;
            if(startrow<=endrow){
            for(int j=endcol;j>=startcol;j--){
                mat[endrow][j]=v;v++;
            }
            }
            endrow--;
            if(startcol<=endcol){
            for(int k=endrow;k>=startrow;k--){
                mat[k][startcol]=v;v++;
            }
            }
            startcol++;

        }
        return mat;
    }
};