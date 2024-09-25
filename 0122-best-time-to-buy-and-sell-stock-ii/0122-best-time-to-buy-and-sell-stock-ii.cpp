class Solution
{
    public:
        int maxProfit(vector<int> &prices)
        {
            int n = prices.size();
            // vector<vector<int>> dp(n, vector<int>(2, -1));
            return helper(0, 1, prices, n);
        }
    int helper(int ind, int buy, vector<int> &prices, int n)
    {
        if (ind == n) return 0;
       	/*Recursive Solution */
                // if(buy==1){
                //     return max(-prices[ind]+helper(ind+1,0,prices,n),0+helper(ind+1,1,prices,n));
                // }
                // else{
                //     return max(prices[ind]+helper(ind+1,1,prices,n),0+helper(ind+1,0,prices,n));
                // }


        vector<vector < int>> dp(n+1, vector<int> (2, 0));
        // if (dp[ind][buy] != -1) return dp[ind][buy];
       /* Memoization
        if (buy == 1)
        {
            dp[ind][buy] = max(-prices[ind] + helper(ind + 1, 0, prices, dp, n),
                               0 + helper(ind + 1, 1, prices, dp, n));
        }
        else
        {
            dp[ind][buy] = max(prices[ind] + helper(ind + 1, 1, prices, dp, n),
                               0 + helper(ind + 1, 0, prices, dp, n));
        }
        */
        //Tabulation
        dp[n][0]=dp[n][1]=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                if (buy == 1)
        {
            dp[ind][buy] = max(-prices[ind] + dp[ind + 1][0],
                               0 + dp[ind + 1][1]);
        }
        else
        {
            dp[ind][buy] = max(prices[ind] + dp[ind + 1][1],
                               0 + dp[ind + 1][0]);
        }
            }
        }
        return dp[0][1];
    }
};
