class Solution {
public:
    int countSubstrings(string s) {
           string answer="";
        int maxlength=0;
        int count=0;
       vector<vector<int>> dp(s.length(),vector<int>(s.length(),0));
       for(int diff=0;diff<s.length();diff++){
        for(int i=0,j=i+diff;j<s.length();i++,j++){
            if(i==j){
                dp[i][j] =1;
            }
            else if (diff==1){
                dp[i][j] =(s[i]==s[j])?2:0;
            }
            else{
                if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j] = dp[i+1][j-1]+2;
                }
            }
            if(dp[i][j]){
                maxlength = max(j-i+1,maxlength);
                count++;
                answer = s.substr(i,maxlength);
            }
        }
       } 
       return count;
    }
};