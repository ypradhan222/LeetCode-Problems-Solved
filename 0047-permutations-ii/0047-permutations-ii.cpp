class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        permute(nums,0);
        return result;
    }
    void permute(vector<int> nums,int index){
        if(index==nums.size()){
            result.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            if(index!=i && nums[i]==nums[index]) continue;
            swap(nums[i],nums[index]);
            permute(nums,index+1);
            // swap(nums[i],nums[index]);
        }
    }
};