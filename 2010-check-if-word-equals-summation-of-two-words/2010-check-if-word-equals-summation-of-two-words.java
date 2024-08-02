class Solution {
    public int getNum(String num){
        StringBuilder str = new StringBuilder();
        for(int i=0;i<num.length();i++){
            str.append(num.charAt(i)-'a');
        }
        return Integer.parseInt(str.toString());
    }
    public boolean isSumEqual(String firstWord, String secondWord, String targetWord) {
      return getNum(firstWord)+getNum(secondWord) == getNum(targetWord);
    }
}