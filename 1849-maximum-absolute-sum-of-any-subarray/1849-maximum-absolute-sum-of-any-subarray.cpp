class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int local=0;
        int global=INT_MIN;
        int mini=0;
        int global_reverse=INT_MAX;
        for(int i=0;i<size(nums);i++){   //Find mxum subarray sum
            local= max(nums[i],local+nums[i]);
            global= max(global,local);
        }
        for(int i=0;i<size(nums);i++){ //find minum subarray sum
            mini=min(nums[i],mini+nums[i]);
            global_reverse= min(global_reverse,mini);
        }
        return max(global,abs(global_reverse)); //max of both
    }
};