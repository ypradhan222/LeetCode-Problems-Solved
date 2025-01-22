class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size(); 
        vector<vector<int>> result(m, vector<int>(n, -1));
        vector<vector<int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        queue<pair<int, int>> que;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    result[i][j] = 0;
                    que.push({i, j});
                }
            }
        }

        while (!que.empty()) {
            pair<int, int> x = que.front();
            que.pop();
            for (auto& v : directions) {
                int newi = x.first + v[0];
                int newj = x.second + v[1];
                if (newi >= 0 && newi < m && newj >= 0 && newj < n && result[newi][newj] == -1) {
                    result[newi][newj] = result[x.first][x.second] + 1;
                    que.push({newi, newj});
                }
            }
        }
        return result;
    }
};
