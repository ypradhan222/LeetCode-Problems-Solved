class Solution {
public:
    bool isVowel(char &ch){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> res(queries.size());
        vector<int> cusum(words.size());
        int sum=0;
        for(int i=0;i<words.size();i++){
            if(isVowel(words[i][0]) && isVowel(words[i].back())){
                sum++;
            }
            cusum[i]=sum;
        }
        for(int i=0;i<queries.size();i++){
            int left=queries[i][0];
            int right= queries[i][1];
            res[i]=cusum[right]- ((left>0)?cusum[left-1]:0);
        }
        return res;
    }
};