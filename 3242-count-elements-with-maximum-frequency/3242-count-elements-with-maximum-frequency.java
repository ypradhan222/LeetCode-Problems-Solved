class Solution {
    public int maxFrequencyElements(int[] nums) {
        int[] count=new int[101];
        for(int num:nums){
            count[num]++;
        }
        int max = Integer.MIN_VALUE;
        for(int num:count){
            max = Math.max(num,max);
        }
        int result=0;
        for(int num:count){
            if(num==max){
                result+=max;
            }
        }
        return result;
    }
}