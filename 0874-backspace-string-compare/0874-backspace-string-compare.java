class Solution {
    public boolean backspaceCompare(String s, String t) {
        Stack<Character> stk1 = new Stack<>();
        Stack<Character> stk2 = new Stack<>();
        for(char c:s.toCharArray()){
            if(c!='#'){
                stk1.push(c);
            }
            else{
                if(!stk1.isEmpty()) stk1.pop();
            }
        }
        for(char c:t.toCharArray()){
            if(c!='#'){
                stk2.push(c);
            }
            else{
                if(!stk2.isEmpty()) stk2.pop();
            }
        }
        return stk1.equals(stk2);
    }
}