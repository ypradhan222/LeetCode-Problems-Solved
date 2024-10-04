class Solution {
public:
    vector<vector<int>> directions{{1,0},{0,1},{-1,0},{0,-1}};
    bool solve(vector<vector<char>>& board,int i,int j,int index,string& word){
        if(index==word.length()){
            return true;
        }
        if(i<0 || i>=board.size() ||j<0||j>=board[0].size() ||board[i][j]!=word[index] || board[i][j]=='#'){
            return false;
        }
        char temp=board[i][j];
        board[i][j]='#';
        for(auto& dir:directions){
            int newi= i+dir[0];
            int newj=j+dir[1];
            if(solve(board,newi,newj,index+1,word)){
                return true;
            }
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n= board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0] && solve(board,i,j,0,word)){
                    return true;
                }
            }
        }
        return false;
    }
};