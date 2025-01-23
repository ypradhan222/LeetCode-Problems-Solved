class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=size(grid);
        int n=size(grid[0]);
        // vector<vector<int>> visited(m,vector<int>(n,false));
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(!visited[i][j] && grid[i][j]==1){
        //             count++;
        //             dfs(grid,visited,i,j,m,n);
        //         }
        //     }
        // }
        // return count;
        vector<int> rowindex(m,0);
        vector<int> colindex(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    rowindex[i]+=1;
                    colindex[j]+=1;
                }
            }
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && (rowindex[i]>1 ||colindex[j]>1)){
                    count++;
                }
            }
        }
        return count;
    }
    // void dfs(vector<vector<int>>& grid,vector<vector<int>>& visited,int i,int j,int m,int n){
    //     visited[i][j]=true;
    // }
    // bool isValid(int i,int j,int m,int n){
    //     return i>=0 && i<m && j>=0 && j<n;
    // }
};