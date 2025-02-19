class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(nums, 0, n - 1, dp) >= 0;
    }
    int helper(vector<int>& nums, int start, int end, vector<vector<int>>& dp) { 
        if (start == end) return nums[start]; 
        if (dp[start][end] != -1) return dp[start][end]; 
        return dp[start][end] = max(
            nums[start] - helper(nums, start + 1, end, dp),
            nums[end] - helper(nums, start, end - 1, dp)
        );
    }
};
