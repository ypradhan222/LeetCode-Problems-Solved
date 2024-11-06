class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> pq;
        vector<int> res;
        for(int num:nums){
            pq.push(num);
        }
        while(!pq.empty()){
            int top= pq.top();
            pq.pop();
            int nexttop=pq.top();
            pq.pop();
            res.push_back(nexttop);
            res.push_back(top);
        }
        return res;
    }
};