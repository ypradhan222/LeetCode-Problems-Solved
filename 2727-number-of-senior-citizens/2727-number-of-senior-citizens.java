class Solution {
    public int countSeniors(String[] details) {
        int count=0;
        for(String st: details){
            String sub = st.substring(11,13);
            if(Integer.parseInt(sub)>60){
                count++;
            }
        }
        return count;
    }
}