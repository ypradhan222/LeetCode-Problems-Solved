class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int peri = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, m, n, peri);
                    return peri; 
                }
            }
        }
        return 0;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int m, int n, int& peri) {
        if (!isValid(i, j, m, n) || grid[i][j] == 0) {
            peri++; 
            return;
        }
        if (grid[i][j] == -1) return; 
        grid[i][j] = -1;  
        vector<vector<int>> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        for (auto& dir : directions) {
            int newi = i + dir[0];
            int newj = j + dir[1];
            dfs(grid, newi, newj, m, n, peri);
        }
    }

    bool isValid(int i, int j, int m, int n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
};