class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1;
        int j=1;
        for(int j=1;j<size(nums);j++){
            if(nums[i-1]!=nums[j]){
                nums[i]=nums[j];
                i+=1;
            }
        }
        return i;
    }
};