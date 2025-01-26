class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> mp;
        for (auto& edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];
            mp[u].push_back(v);
        }
        vector<bool> res(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            vector<bool> visited(numCourses, false);
            int u = queries[i][0];
            int v = queries[i][1];
            res[i] = dfs(mp, visited, u, v);
        }
        return res;
    }
    bool dfs(unordered_map<int, vector<int>>& mp, vector<bool>& visited, int src, int des) {
        if (src == des) return true;  
        visited[src] = true;
        for (int adj : mp[src]) { 
            if (!visited[adj] && dfs(mp, visited, adj, des)) {
                return true;  
            }
        }
        return false;  
    }
};
