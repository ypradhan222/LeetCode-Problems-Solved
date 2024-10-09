class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        unordered_map<int,vector<int>> adj;
        for(auto &vec:prerequisites){
            int a = vec[0];
            int b= vec[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        return topo(adj,numCourses,indegree);
    }
    bool topo(unordered_map<int,vector<int>>& adj,int n,vector<int>& indegree){
        //1
        queue<int> que;
        int count=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                que.push(i);
                count++;
            }
        }
        while(!que.empty()){
            int u= que.front();
            que.pop();
            for(int &v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    que.push(v);count++;
                }
            }
        }
        return count==n;
    }
};