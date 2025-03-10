class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int i=0;
        int j=nums.size()-1;
        int res=0;
        while(i<j){
            int sum=nums[i]+nums[j];
            res=max(sum,res);
            i++;j--;
        }
        return res;
    }
};