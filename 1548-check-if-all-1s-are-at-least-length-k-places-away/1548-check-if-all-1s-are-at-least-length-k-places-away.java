class Solution {
    private int count;
    public boolean kLengthApart(int[] nums, int k) {
//         for(int i=0;i<nums.length-1;i++){
//             if(nums[i]==1){
//                 int j=i+1;
//                 count=0;
//                 while(nums[j]!=1 && count<k ){
//                     count++;
//                     j++;
//                 }
//                 i=j-1;
//             }
//             else{continue;}
//     }
//     System.gc();
//     if(count>=k){
//         return true;
//     }
//     else return false;
int lastOneIndex = -k - 1; 
    
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 1) {
                if (i - lastOneIndex - 1 < k) {
                    return false; 
                }
                lastOneIndex = i;  
            }
        }
        return true;
}
}