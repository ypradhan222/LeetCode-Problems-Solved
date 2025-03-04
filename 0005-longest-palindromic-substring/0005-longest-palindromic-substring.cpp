class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int maxlen=0;
        vector<vector<int>> t(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            t[i][i]=1;
            maxlen=1;
        }
        int idx=0;
        for(int len=2;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j=i+len-1;
                if(s[i]==s[j] && len==2){
                    t[i][j]=1;
                    maxlen=len;
                    idx=i;
                }
                else if(s[i]==s[j] && t[i+1][j-1]){
                    t[i][j]=1;
                    maxlen=max(maxlen,j-i+1);
                    idx=i;
                }
            }
        }
        return s.substr(idx,maxlen);
    }
};