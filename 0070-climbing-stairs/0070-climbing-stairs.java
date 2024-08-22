class Solution {
    public int climbStairs(int n) {
       return fib(n);
    }
    int fib(int n){
        int[] arr =new int[n+1];
       arr[0]=1;
       arr[1]=2;
       for(int i=2;i<=n;i++){
        arr[i]=arr[i-1]+arr[i-2];
       }
       return arr[n-1];
    }
}