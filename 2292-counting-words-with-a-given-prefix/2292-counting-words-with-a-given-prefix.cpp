class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        for(int i=0;i<size(words);i++){
            if(words[i].substr(0,pref.size()).find(pref)!=string::npos){
                count++;
            }
        }
        return count;
    }
};