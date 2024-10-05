class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        backtrack(k,n,curr,1);
        return res;
    }
    void backtrack(int k,int n,vector<int>& curr,int index){
        if(k==0 && n==0 ){ 
            res.push_back(curr);
            return;
        }
        if(index>9) return;
        for(int i=index;i<=9;i++){
            curr.push_back(i);
            backtrack(k-1,n-i,curr,i+1);
            curr.pop_back();
        }
    }
};