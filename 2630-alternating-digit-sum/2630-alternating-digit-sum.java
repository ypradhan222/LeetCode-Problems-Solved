class Solution {
    public int alternateDigitSum(int n) {
        int answer=0;
        int sign =1;
        String num =""+n;
        for(char c:num.toCharArray()){
            answer+=(sign* Integer.parseInt(""+c));
            sign*=-1;
        }
        return answer;
    }
}