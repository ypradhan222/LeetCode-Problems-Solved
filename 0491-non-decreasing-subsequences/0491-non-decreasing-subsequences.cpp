class Solution {
public:
vector<vector<int>> result;
     vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> curr;
        solve(0,curr,nums);
        return result;
    }
    void solve(int index,vector<int>& curr,vector<int>& nums){
        if(curr.size()>=2){
            result.push_back(curr);
        }
        unordered_set<int> st;
        for(int i=index;i<nums.size();i++){
            if( (curr.empty() || nums[i]>=curr.back()) && (st.find(nums[i])==st.end())){
                curr.push_back(nums[i]);
                solve(i+1,curr,nums);
                curr.pop_back();
                st.insert(nums[i]);
            }
        }
    }
};