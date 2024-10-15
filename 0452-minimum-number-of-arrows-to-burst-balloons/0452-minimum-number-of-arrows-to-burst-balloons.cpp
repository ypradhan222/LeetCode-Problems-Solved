class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int count=1;
        vector<int> prev=points[0];
        for(int i=1;i<points.size();i++){
            int currstart=points[i][0];
            int currend=points[i][1];
            int prevstart= prev[0];
            int prevend=prev[1];
            if(currstart>prevend){
                count++;
                prev=points[i];
            }
            else{
                prev[0] = max(currstart,prevstart);
                prev[1]= min(currend,prevend);
            }
        }
        return count;
    }
};