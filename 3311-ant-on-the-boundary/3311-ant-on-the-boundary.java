class Solution {
    public int returnToBoundaryCount(int[] nums) {
        int count=0;
        int boundry=-1;
        for(int i=0;i<nums.length;i++){
            if(nums[i]>0){
                boundry+=nums[i];
                if(boundry==-1){
                    count++;
                }
            }
            else if(nums[i]<0){
                boundry-=Math.abs(nums[i]);
                if(boundry==-1){
                    count++;
                }
            }
        }
        return count;
    }
}