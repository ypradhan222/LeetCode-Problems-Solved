class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return {};
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            if(i > 0 && nums[i]==nums[i-1]) continue;
            int n1=nums[i];
            int target =-n1;
            twoSum(nums,target,i+1,n-1);
        }
        return res;
    }
    void twoSum(vector<int>& nums,int target,int i,int j){
        while(i<j){
            if(nums[i]+nums[j]>target){
                j--;
            }
            else if(nums[i]+nums[j]<target){
                i++;
            }
            else{
                //remove duplicates
                while(i<j &&nums[i]==nums[i+1]) i++;
                while(i<j && nums[j]==nums[j-1]) j--;
                res.push_back({-target,nums[i],nums[j]});
                i++;j--;
            }
        }
    }
};