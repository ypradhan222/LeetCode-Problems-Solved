class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        transpose(matrix,n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n/2;j++){
                int temp=matrix[i][n-j-1];
                matrix[i][n-j-1] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
    void transpose(vector<vector<int>>& matrix,int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
};