class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=size(nums);
        int i=0;
        while(i<n-1){
            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }
            i++;
        }
        int x=0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[x] = nums[i];
                if (x != i) {
                    nums[i] = 0;
                }
                x++;
            }
        }
        return nums;
    }
};