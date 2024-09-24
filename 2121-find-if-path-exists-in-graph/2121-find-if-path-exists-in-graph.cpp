class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> mp;
        for(vector<int> vec:edges){
            mp[vec[0]].push_back(vec[1]);
            mp[vec[1]].push_back(vec[0]);
        }
        vector<bool> visited(n,false);
        visited[source]= true;
        return bfs(mp,source,destination,visited,n);
    }
    // bool dfs(unordered_map<int,vector<int>>& graph,int source,int destination,vector<bool>& visited,int n){
    //     if(source==destination){
    //         return true;
    //     }
    //     visited[source]= true;
    //     for(auto neighbor: graph[source]){
    //         if(!visited[neighbor]){
    //             if(dfs(graph,neighbor,destination,visited,n)) return true;;
    //         }
    //     }

    //     return false;
    // }
    bool bfs(unordered_map<int,vector<int>>& graph,int source,int destination,vector<bool>& visited,int n){
        queue<int> q;
        q.push(source);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            if(curr==destination){
                return true;
            }
            for(int neighbor:graph[curr]){
                if(!visited[neighbor]){
                    q.push(neighbor);
                    visited[neighbor]= true;
                }
            }
        }
        return false;
    }
};