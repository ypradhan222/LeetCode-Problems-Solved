class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()== 1) {
            return nums[0];
        }
        if (nums.size()== 2) {
            return max(nums[0], nums[1]);
        }
        return max(rob1(nums,0,nums.size()- 2), rob1(nums,1, nums.size()-1));
    }
    int rob1(vector<int>& nums, int start, int end) {
        if (start == end) return nums[start];
        vector<int> dp(end - start + 1, 0);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);
        for (int i = 2; i <= end - start; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[start + i]);
        }
        return dp[end-start];
    }
};
