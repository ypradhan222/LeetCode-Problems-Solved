class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, INT_MAX));
        for(int i=0;i<=coins.size();i++){
            dp[i][0] =0;
        }
        // for(int i=0;i<=amount;i++){
        //     dp[0][i]=-1;
        // }
        for(int i=1;i<=coins.size();i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]>j){
                    dp[i][j]= dp[i-1][j];
                }
                else{
                    if(dp[i][j-coins[i-1]]!=INT_MAX) dp[i][j] = min(dp[i-1][j],dp[i][j-coins[i-1]]+1);
                    else dp[i][j]= dp[i-1][j];
                }
            }
        }
        return dp[coins.size()][amount]==INT_MAX ? -1  : dp[coins.size()][amount];

    }
};