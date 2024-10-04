class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1);
        int i2=1,i3=1,i5=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            int newug2=dp[i2]*2;
            int newug3=dp[i3]*3;
            int newug5=dp[i5]*5;
            int mini = min({newug2,newug3,newug5});
            dp[i]= mini;
            if(mini==newug2) i2++;
            if(mini==newug3) i3++;
            if(mini==newug5) i5++;
        }
        return dp[n];
    }
};