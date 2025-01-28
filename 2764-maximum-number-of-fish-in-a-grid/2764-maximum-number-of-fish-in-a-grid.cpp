class Solution {
public:
    vector<vector<int>> directions={{-1,0},{1,0},{0,1},{0,-1}};
    int findMaxFish(vector<vector<int>>& grid) {
        int m=size(grid);
        int n=size(grid[0]);
        int maxfish=0;
        vector<vector<bool>> visted(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0){
                    maxfish=max(maxfish,dfs(i,j,grid));
                }
            }
        }
        return maxfish;
    }
    int dfs(int i,int j,vector<vector<int>>& grid){
        if(i<0 || i>=size(grid) ||j<0||j>=size(grid[0]) ||grid[i][j]==0){
            return 0;
        }
        int count=grid[i][j];
        grid[i][j]=0;
        for(auto &dir:directions){
            int newi=dir[0]+i;
            int newj=dir[1]+j;
            count+=dfs(newi,newj,grid);
        }
        return count;
    }
};