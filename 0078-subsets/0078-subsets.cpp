class Solution {
    vector<vector<int>> result ;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sublist;
        findSubset(nums,0,sublist);
        return result;
    }
    void findSubset(vector<int>& nums,int index,vector<int>& sublist){
        if(nums.size()==index){
            result.push_back(sublist);
            return;
        }
        //Pick
        sublist.push_back(nums[index]);
        findSubset(nums,index+1,sublist);
        //backtrack
        sublist.pop_back();

        //Not pick
        findSubset(nums,index+1,sublist);
    }
};