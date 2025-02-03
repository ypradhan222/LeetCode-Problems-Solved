class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        int increasing = 1, decreasing = 1;
        int maxLen = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i-1]) {
                increasing++;
                decreasing = 1;
            } 
            else if (nums[i] < nums[i-1]) {
                decreasing++;
                increasing = 1;
            } 
            else {
                increasing = 1;
                decreasing = 1;
            }
            maxLen = max({maxLen, increasing, decreasing});
        }
        
        return maxLen;
    }
};
