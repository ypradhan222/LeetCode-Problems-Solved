class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> mp;
        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];
            vector<bool> visited(size(edges),false);
            if(mp.find(u)!=mp.end() && mp.find(v)!=mp.end() && dfs(visited,mp,u,v)){
                return edge;
            }
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        return {};

    }
    bool dfs(vector<bool>& visited,unordered_map<int,vector<int>>& mp,int u,int v){
        visited[u]=true;
        if(u==v) return true;
        for(auto &ngh:mp[u]){
            if(visited[ngh]) continue;
            if(dfs(visited,mp,ngh,v)){
                return true;
            }
        }
        return false;

    }
};