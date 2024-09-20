class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wd(wordDict.begin(),wordDict.end());
        vector<int> dp(s.length()+1,-1);
        return solve(0,s,wd,dp);
    }
    private:
        bool solve(int ind,string& s,unordered_set<string>& wd,vector<int>& dp){
        if(dp[ind]!=-1) return dp[ind];

        if(ind == s.length()){
            return true;
        }
        if(wd.find(s)!=wd.end()){
            return true;
        }
        for(int i=1;i<=s.length();i++){
            string temp= s.substr(ind,i);
            if(wd.find(temp)!=wd.end() && solve(ind+i,s,wd,dp)){
                return dp[ind]=true;
            }
        }
        return dp[ind]=false;
        }
};