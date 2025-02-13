class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        if(size(nums)<2) return 0;
        priority_queue<long,vector<long>,greater<long>> pq(begin(nums),end(nums));
        int count=0;
        while(!pq.empty()&&pq.top()<k){
            long small=pq.top();
            pq.pop();
            long second=pq.top();
            pq.pop();
            pq.push(small*2+second);
            count++;
        }
        return count;
    }
};