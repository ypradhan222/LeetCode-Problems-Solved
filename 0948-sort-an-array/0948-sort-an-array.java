
class Solution {
    public int[] sortArray(int[] nums) {
        Integer[] freq=new Integer[100001];
        for(int e:nums) freq[e+50000]=freq[e+50000]==null?1:freq[e+50000]+1;
        int i=0,k=-50000; 
        for(Integer e:freq){
            if(e!=null){ 
                for(int j=0;j<e;j++) nums[i++]=k;
            }
           k++; 
        }
        return nums;
    }
}