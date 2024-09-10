class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size());
        if(nums.size()==1){
            return nums[0];
        }
        dp[0] = nums[0];
        dp[1] = max(dp[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            dp[i] =max(dp[i-1],dp[i-2]+nums[i]);

        }
        int maxi = INT_MIN;
        for(int i=0;i<dp.size();i++){
            maxi = max(maxi,dp[i]);
        }
        return maxi;
        // int sum1 =0;int sum2=0;
        // for(int i=0;i<nums.size();i++){
        //     if(i%2==0){
        //         sum1+=nums[i];
        //     }
        //     else if(i%2!=0){
        //         sum2+=nums[i];
        //     }
        // }
        // return max(sum1,sum2);
    }
};