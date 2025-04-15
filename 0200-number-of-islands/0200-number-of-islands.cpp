class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m= grid.size();
        int n = grid[0].size();
        // vector<vector<bool>> visited(m,vector<bool>(n,false));
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid,i,j,m,n);
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>& grid,int i,int j,int m,int n){
        if(grid[i][j]==-1) return;
        grid[i][j]=-1;
        vector<vector<int>>  directions= {{0,-1},{0,1},{-1,0},{1,0}};
        for(int k=0;k<4;k++){
            int newi = i+directions[k][0];
            int newj =j+directions[k][1];
            if(safePosition(newi,newj,m,n) && grid[newi][newj]=='1'){
                dfs(grid,newi,newj,m,n);
            }
        }
    }
    bool safePosition(int i,int j,int m,int n){
        return i>=0 && i<m && j>=0 && j<n;
    }
};