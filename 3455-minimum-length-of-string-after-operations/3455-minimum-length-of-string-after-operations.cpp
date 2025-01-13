class Solution {
public:
    int minimumLength(string s) {
        int n= s.size();
        vector<int> count(26,0);
        int deleted=0;
        for(int i=0;i<n;i++){
            count[s[i]-'a']++;
            if(count[s[i]-'a']==3){
                count[s[i]-'a']-=2;
                deleted+=2;
            }
        }
        return n-deleted;
    }
};