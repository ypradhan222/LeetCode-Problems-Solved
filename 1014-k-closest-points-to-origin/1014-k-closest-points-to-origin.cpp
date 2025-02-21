class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        if(points.size()==0) return ans;
        priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<points.size();i++){
            int d = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            if(pq.size()<k){
                pq.push({d,{points[i][0],points[i][1]}});
            }
            else{
                if(d<pq.top().first){
                    pq.pop();
                    pq.push({d,{points[i][0],points[i][1]}});
                }
            }
        }
        while(!pq.empty()){
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};