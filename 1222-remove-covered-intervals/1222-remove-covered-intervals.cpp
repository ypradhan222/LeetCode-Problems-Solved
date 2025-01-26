class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int left=-1;int right=-1;int res=0;
        sort(begin(intervals),end(intervals));
        for(auto& interval:intervals){
            if(interval[0]>left && interval[1]>right){
                left=interval[0];
                res++;
            }
            right=max(right,interval[1]);
        }
        return res;
    }
};