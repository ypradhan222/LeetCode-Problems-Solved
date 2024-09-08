class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        backtrack(1,n,temp,k);
        return res;
    }
    void backtrack(int index,int n,vector<int>& temp,int k){
        if(temp.size()==k){
            res.push_back(temp);
            return;
        }
        for(int i=index;i<=n;i++){
            temp.push_back(i);
            backtrack(i+1,n,temp,k);
            temp.pop_back();
        }
    }
};