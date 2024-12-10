class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0,right=0,maxi=0,zeros=0;
        while(right<nums.size()){
            if(nums[right]==0) zeros++;
            if(zeros>k){
                if(nums[left]==0) zeros--;
                left++;
            }
            if(zeros<=k){
                int len=right-left+1;
                maxi=max(maxi,len);
            }
            right++;
        }
        return maxi;
    }
};