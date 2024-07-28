class Solution {
    public char repeatedCharacter(String s) {
        int[] count = new int[26];
        for(int i=0;i<s.length();i++){
            int c = s.charAt(i)-'a';
            count[c]++;
            if(count[c]>1){
                return s.charAt(i);
            }
        }
        return s.charAt(0);
    }
}