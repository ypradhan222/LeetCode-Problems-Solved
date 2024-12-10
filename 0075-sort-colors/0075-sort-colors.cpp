class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0,end = nums.size()-1;
        int i =0;
        while(i<=end){
            if(nums[i]==0){
                swap(nums[i],nums[start]);
                i++;start++;
            }
            else if(nums[i]==2){
                swap(nums[i],nums[end]);
                end--;
            }else{
                i++;
            }
        }
    }
};