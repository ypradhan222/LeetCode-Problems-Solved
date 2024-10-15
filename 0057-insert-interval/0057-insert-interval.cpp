class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i=0;
        vector<vector<int>> res;
        while(i<intervals.size()){
            if(intervals[i][1]<newInterval[0]){
                res.push_back(intervals[i]);
            }
            else if(intervals[i][0]>newInterval[1]){
                break;
            }
            else {
                newInterval[0]= min(intervals[i][0],newInterval[0]);
                newInterval[1]= max(intervals[i][1],newInterval[1]);
            }
            i++;
        }
        res.push_back(newInterval);
        while(i<intervals.size()){
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};