class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false; 
        int target = sum / 2;
        return subsetSumToTarget(nums.size(), target, nums);
    }

    bool subsetSumToTarget(int n, int k, vector<int>& nums) {
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
        for (int x = 0; x < n; x++) {
            dp[x][0] = true;
        }
        if (nums[0] <= k) {
            dp[0][nums[0]] = true;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                bool notTaken = dp[i - 1][j];
                bool taken = false;
                if (nums[i] <= j) {
                    taken = dp[i - 1][j - nums[i]];
                }
                dp[i][j] = notTaken || taken;
            }
        }

        return dp[n - 1][k];  
    }
};
