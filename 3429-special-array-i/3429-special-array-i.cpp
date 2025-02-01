class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(size(nums)==1)return true;
        for(int i=0;i<size(nums)-1;i++){
            if(nums[i]%2 == nums[i+1]%2) return false;
        }
        return true;
    }
};