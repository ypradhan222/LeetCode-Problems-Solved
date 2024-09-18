class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        vector<int> ways(nums.size(),1);
        int maxlength=1;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]  && dp[i]<dp[j]+1){
                    dp[i] = max(dp[i],dp[j]+1);
                    ways[i]= ways[j];
                }
                else if(nums[j]<nums[i] && dp[i]==dp[j]+1 ){
                    ways[i]+=ways[j];
                }
            }
            maxlength= max(maxlength,dp[i]);
        }
       int count=0;
       for(int i=0;i<nums.size();i++){
        if(dp[i]==maxlength){
            count+=ways[i];
        }
       }
        return count;
    }
};