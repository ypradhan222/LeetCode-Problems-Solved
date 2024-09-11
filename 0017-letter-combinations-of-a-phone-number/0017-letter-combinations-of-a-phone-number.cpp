class Solution {
public:
    vector<string> result;
    vector<string> letterCombinations(string digits) {
        map<char,string> mp;
        mp['2'] ="abc";
        mp['3'] ="def";
        mp['4'] ="ghi";
        mp['5'] ="jkl";
        mp['6'] ="mno";
        mp['7'] ="pqrs";
        mp['8'] ="tuv";
        mp['9'] ="wxyz";
       
        backtrack(digits,0,"",mp);
        return result;
    }
    void backtrack(string digits,int index,string temp,map<char,string> mp){
        if(index==digits.length()){
            if(temp!=""){
            result.push_back(temp);

            }
            return;
        }
        char cur = digits[index];
        string curralpha = mp[cur];
        for(int i=0;i<curralpha.length();i++ ){
            temp+=curralpha[i];
            backtrack(digits,index+1,temp,mp);
            temp = temp.substr(0,temp.length()-1);
        }
    }
};