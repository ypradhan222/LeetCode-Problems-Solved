class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){ //not visited
                if(BFS(graph,i,color,1)==false){
                    return false;
                }
            }
        }
        return true;
    }
    bool BFS(vector<vector<int>>& graph,int curr,vector<int>& color,int currcolor){
        queue<int> que;
        que.push(curr);
        color[curr]=currcolor;
        while(!que.empty()){
            int u=que.front();
            que.pop();
            for(int &v:graph[u]){
                if(color[v]==color[u]){
                    return false;

                }
                else if(color[v]==-1){
                    color[v]=1-color[u];
                    que.push(v);
                }
            }
        }
        return true;

    }
};