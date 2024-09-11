class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp ;
        backtrack(0,target,temp,candidates);
        return result;
    }
    void backtrack(int index,int target,vector<int>& temp,vector<int>& candidates){
       if(index==candidates.size()){
        if(target==0){
            result.push_back(temp);
        }
        return;
       }
       if(candidates[index]<=target){
        temp.push_back(candidates[index]);
        backtrack(index,target-candidates[index],temp,candidates);
        temp.pop_back();
       }
       backtrack(index+1,target,temp,candidates);
    }
};