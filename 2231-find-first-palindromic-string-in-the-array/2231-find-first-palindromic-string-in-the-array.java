class Solution {
    public String firstPalindrome(String[] words) {
        for(String word:words){
            StringBuilder str = new StringBuilder(word);
            if(word.equals(str.reverse().toString())){
                return word;
            }
        }
        return "";
    }
}