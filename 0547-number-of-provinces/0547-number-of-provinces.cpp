class Solution
{
    public:
        int findCircleNum(vector<vector < int>> &isConnected)
        {
            int n = isConnected.size();
            int count = 0;
            vector<bool> visited(n, false);
            for (int i = 0; i < n; i++)
            {
                if (!visited[i])
                {
                    count++;
                    dfs(isConnected, i, visited, n);
                }
            }
            return count;
        }
    void dfs(vector<vector < int>> &adj, int ind, vector< bool > &visited, int n)
    {
       	visited[ind]= true;
        for (int i = 0; i < n; i++)
        {
            if (adj[ind][i] && !visited[i])
            {
                visited[i] = true;
                dfs(adj, i, visited, n);
            }
        }
    }
};