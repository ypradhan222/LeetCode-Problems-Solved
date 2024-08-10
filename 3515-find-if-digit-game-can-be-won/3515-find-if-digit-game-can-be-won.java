class Solution {
    public boolean canAliceWin(int[] nums) {
        int singlesum=0;
        int doublesum=0;
        for(int num:nums){
            if(num<=9){
                singlesum+=num;
            }
            else{
                doublesum+=num;
            }
        }
        return singlesum!=doublesum;
    }
}