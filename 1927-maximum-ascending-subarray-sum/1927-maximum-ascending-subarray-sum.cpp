class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res=nums[0];
        int maxSum=nums[0];
        for(int i=1;i<size(nums);i++){
            if(nums[i-1]<nums[i]){
                res+=nums[i];
            }
            else{
                maxSum=max(maxSum,res);
                res=nums[i];
            }
        }
        return max(maxSum,res);
    }
};