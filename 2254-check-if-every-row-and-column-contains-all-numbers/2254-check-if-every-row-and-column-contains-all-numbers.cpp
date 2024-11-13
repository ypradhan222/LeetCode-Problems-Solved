class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n; i++) {
            unordered_set<int> rowSet, colSet;           
            for (int j = 0; j < n; j++) {
                int rowVal = matrix[i][j];
                int colVal = matrix[j][i];
                if (rowVal < 1 || rowVal > n || colVal < 1 || colVal > n) {
                    return false;
                }
                if (rowSet.count(rowVal) || colSet.count(colVal)) {
                    return false;
                }
                rowSet.insert(rowVal);
                colSet.insert(colVal);
            }
        }
        
        return true;
    }
};