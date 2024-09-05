class Solution {
public:
    vector<vector<int>>  result;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         vector<int> sublist;
        sort(nums.begin(),nums.end());
        findSubset(nums,0,sublist);
        return result;
    }
    void findSubset(vector<int>& nums,int index,vector<int>& sublist){
        // if(nums.size()==index){
            result.push_back(sublist);
            // return;
        // }
        for(int i=index;i<nums.size();i++){
        if(i> index && nums[i]==nums[i-1]) continue;
        //Pick
        sublist.push_back(nums[i]);
        findSubset(nums,i+1,sublist);
        //backtrack
        sublist.pop_back();

        //Not pick
        // findSubset(nums,index+1,sublist); 
        }
    }
};