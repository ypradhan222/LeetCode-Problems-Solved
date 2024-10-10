class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(numCourses,0);
        for(auto &vec:prerequisites){
            int u= vec[0];
            int v= vec[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        return topologicalSort(adj,indegree,numCourses);
    }
    vector<int> topologicalSort(unordered_map<int,vector<int>>& adj,vector<int>& indegree,int n){
        vector<int> res;
        queue<int> que;
        int count=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                que.push(i);
                count++;
                res.push_back(i);
            }
        }
        while(!que.empty()){
            int u= que.front();
            que.pop();
            for(int &v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    que.push(v);
                    count++;
                    res.push_back(v);
                }
            }
        }
        if(count==n){
            return res;
        }
        return {};
    }
};