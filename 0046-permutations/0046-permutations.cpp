class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        track(nums,0);
        return res;
    }
    void track(vector<int>& nums,int index){
        // vector<int> v
        if(index==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            track(nums,index+1);
            swap(nums[i],nums[index]);
        }
    }
};