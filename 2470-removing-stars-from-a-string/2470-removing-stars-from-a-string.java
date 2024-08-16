class Solution {
    public String removeStars(String s) {
        Stack<Character> stk = new Stack();
        for(char c:s.toCharArray()){
            if(c!='*'){
                stk.push(c);
            }
            else{
                if(!stk.isEmpty()){
                    stk.pop();
                }
            }
        }
        StringBuilder st= new StringBuilder();
        while(!stk.isEmpty()){
            st.append(stk.pop());
        }
        return st.reverse().toString();
    }
}