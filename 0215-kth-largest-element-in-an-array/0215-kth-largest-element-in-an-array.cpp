class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // sort(nums.begin(),nums.end(),greater<int>());
        // return nums[k-1];
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int& num:nums){
            pq.push(num);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();

    }
};