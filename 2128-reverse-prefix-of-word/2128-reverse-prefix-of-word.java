class Solution {
    public String reversePrefix(String word, char ch) {
            int index = word.indexOf(ch);
            String  sub = word.substring(0,index+1);
            StringBuilder st = new StringBuilder(sub);
            StringBuilder  reverse = st.reverse();
            String result = reverse.toString();
            for(int i=index+1;i<word.length();i++){
                result+=word.charAt(i);
            }
            return result;
    }
}