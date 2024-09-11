class Solution {
public:
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        if(n<=0){
            return result;
        }
        backtrack(n,0,"");
        return result;
    }
    void backtrack(int left,int right,string temp){
        if(left==0 && right==0){
            result.push_back(temp);
            return;
        }
        if(left>0){
            backtrack(left-1,right+1,temp+"(");
        }
        if(right>0){
            backtrack(left,right-1,temp+")");
        }
    }
};