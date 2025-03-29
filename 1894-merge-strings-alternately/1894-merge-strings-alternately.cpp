class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res="";
        int len1=size(word1);int len2=size(word2);
        int i=0;int j=0;
        while(i<len1 && j<len2){
            res+=word1[i];
            res+=word2[j];
            i++;j++;
        }
        while(i<len1){
            res+=word1[i];i++;
        }
        while(j<len2){
            res+=word2[j];j++;
        }
        return res;
    }
};