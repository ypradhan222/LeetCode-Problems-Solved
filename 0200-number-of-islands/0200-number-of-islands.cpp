class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m= grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    count++;
                    dfs(grid,visited,i,j,m,n);
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>& grid,vector<vector<bool>>& visited,int i,int j,int m,int n){
        visited[i][j]= true;
        vector<vector<int>>  directions= {{0,-1},{0,1},{-1,0},{1,0}};
        for(int k=0;k<4;k++){
            int newi = i+directions[k][0];
            int newj =j+directions[k][1];
            if(safePosition(newi,newj,m,n) && grid[newi][newj]=='1' && !visited[newi][newj]){
                dfs(grid,visited,newi,newj,m,n);
            }
        }
    }
    bool safePosition(int i,int j,int m,int n){
        return i>=0 && i<m && j>=0 && j<n;
    }
};