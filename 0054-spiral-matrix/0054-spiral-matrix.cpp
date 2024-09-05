class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m =matrix.size();
        int n = matrix[0].size();
        vector<int> vec;
        int startRow=0;
        int endRow = m-1;
        int startCol=0;
        int endCol=n-1;
        while(startRow<=endRow && startCol<=endCol){
            for(int i=startCol;i<=endCol;i++){
                vec.push_back(matrix[startRow][i]);
            }
            startRow+=1;
            for(int i=startRow;i<=endRow;i++){
                vec.push_back(matrix[i][endCol]);
            }
            endCol-=1;
            if(startRow<=endRow){
               for(int i=endCol;i>=startCol;i--){
                vec.push_back(matrix[endRow][i]);
            } 
                endRow-=1;
            }
            if(startCol<=endCol){
                for(int i=endRow;i>=startRow;i--){
                vec.push_back(matrix[i][startCol]);
            }
            startCol+=1;
            }
        }
        return vec;
    }
};