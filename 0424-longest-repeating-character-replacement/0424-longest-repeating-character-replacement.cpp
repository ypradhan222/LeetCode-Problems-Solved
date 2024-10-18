class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0,right=0,maxlen=0,maxfreq=0;
        vector<int> count(26,0);
        while(right<s.size()){
            count[s[right]-'A']++;
            maxfreq=max(maxfreq,count[s[right]-'A']);
            if((right-left+1)-maxfreq>k){
                count[s[left]-'A']--;
                maxfreq=0;
                left++;
            }
            if((right-left+1)-maxfreq<=k){
                maxlen=max(maxlen,right-left+1);
            }
            right++;
        }
        return maxlen;

    }
};