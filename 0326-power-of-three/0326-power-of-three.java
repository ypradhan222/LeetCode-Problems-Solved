class Solution {
    public boolean isPowerOfThree(int n) {
        if(n==3 || n==1){
            return true;
        }
        if(n<3 ){
            return false;
        }
        return n%3==0 && isPowerOfThree(n/3);
    }
}