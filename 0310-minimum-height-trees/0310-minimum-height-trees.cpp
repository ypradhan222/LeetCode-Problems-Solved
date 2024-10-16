class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
       if(n==1) return {0};
         vector<int> indegree(n);
        unordered_map<int,vector<int>> adj;
        vector<int> res;

        for(auto &vec:edges){
            int a = vec[0];
            int b= vec[1];
            adj[b].push_back(a);
            indegree[a]++;
            indegree[b]++;
            adj[a].push_back(b);
        }
        queue<int> que;
        for(int i=0;i<n;i++){
            if(indegree[i]==1){
                que.push(i);
            }
        }
        while(n>2){
            int size=que.size();
            n-=size;
            while(size--){
                int u=que.front();
                que.pop();
                for(int &v:adj[u]){
                    indegree[v]--;
                    if(indegree[v]==1) que.push(v);
                }
            }
        }
        while(!que.empty()){
            res.push_back(que.front());
            que.pop();
        }
        return res;
    }
};