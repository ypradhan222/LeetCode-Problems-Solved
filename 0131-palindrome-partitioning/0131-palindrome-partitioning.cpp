class Solution {
public:
    vector<vector<string>> result;
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        backtrack(temp,s);
        return result;
    }
    bool isPallindrome(string s){
        string reversed(s.rbegin(),s.rend());
        return reversed==s;
    }
    void backtrack(vector<string>& temp,string s){
       if(s.length()==0){
        result.push_back(temp);
        return;
       } 
       for(int i=0;i<s.length();i++){
        string sub = s.substr(0,i+1);
        if(isPallindrome(sub)){
            temp.push_back(sub);
            backtrack(temp,s.substr(i+1));
            temp.pop_back();
        }
       }
    }
};