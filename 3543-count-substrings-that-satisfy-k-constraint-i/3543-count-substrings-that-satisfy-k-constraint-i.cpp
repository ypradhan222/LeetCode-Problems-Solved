class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int j=0;
        int i=0;
        int count=0;
        vector<int> help(2,0);
        while(j<size(s)){
            help[s[j]-'0']++;
            while(help[0]>k && help[1]>k){
                help[s[i]-'0']--;
                i++;
            }
            count+=(j-i+1);
            j++;
        }
        return count;
    }
};