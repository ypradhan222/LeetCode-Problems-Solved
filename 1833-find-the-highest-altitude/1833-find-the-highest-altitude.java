class Solution {
    public int largestAltitude(int[] gain) {
        int[] result = new int[gain.length+1];
        result[0]=0;
        int sum=0;
        int max=0;
        for(int i=0;i<gain.length;i++){
            sum+=gain[i];
            result[i+1]=sum;
        }
        for(int num:result){
            max= Math.max(num,max);
        }
        return max;
    }
}