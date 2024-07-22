class Solution {
    public String[] sortPeople(String[] names, int[] heights) {
        HashMap<Integer,String> map = new HashMap<>();
        for(int i=0;i<heights.length;i++){
            map.put(heights[i],names[i]);
        }
        ArrayList<Integer> list= new ArrayList<>(map.keySet());
        Collections.sort(list);
        String[] result = new String[heights.length];
        for(int i=list.size()-1;i>=0;i--){
            result[list.size()-i-1]=map.get(list.get(i));
        }
        return result;
    }
}