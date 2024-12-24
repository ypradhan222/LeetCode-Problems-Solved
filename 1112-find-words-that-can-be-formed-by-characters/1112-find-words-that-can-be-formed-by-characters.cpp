class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> vec(26,0);
        for(int i=0;i<chars.size();i++){
            vec[chars[i]-'a']++;
        }
        int result=0;
        for(string& word:words){
            vector<int> count(26,0);
            for(char& ch:word){
                count[ch-'a']++;
            }
            bool flag=true;
            for(int i=0;i<26;i++){
                if(count[i]>vec[i]){
                    flag=false;break;
                }
            }
            if(flag==true){
                result+=word.size();
            }
        }
        return result;
    }
};