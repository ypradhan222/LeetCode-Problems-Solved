class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n= obstacleGrid[0].size();
        vector<vector<int>> grid(m,vector<int>(n,0));
         if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
        for(int i=0;i<m;i++){
            if(obstacleGrid[i][0]==1){
                break;
            }
            else grid[i][0]=1;
        }
         for(int i=0;i<n;i++){
            if(obstacleGrid[0][i]==1){
                // grid[0][i]=0;
                break;
            }
            else grid[0][i]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    grid[i][j]=0; continue;
                }
                else{
                    grid[i][j]=grid[i-1][j]+grid[i][j-1];
                }
            }
        }
        return grid[m-1][n-1];
    }
};