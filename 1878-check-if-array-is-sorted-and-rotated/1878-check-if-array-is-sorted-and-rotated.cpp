class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        for(int i=0;i<size(nums);i++){
            if(nums[i]>nums[(i+1)%size(nums)]){
                count++;
            }
        }
        return count<=1;
    }
};