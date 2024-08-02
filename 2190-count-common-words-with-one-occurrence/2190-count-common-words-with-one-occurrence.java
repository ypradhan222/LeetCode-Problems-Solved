class Solution {
    public int countWords(String[] words1, String[] words2) {
        HashMap<String,Integer> map = new HashMap<>();
        HashMap<String,Integer> map2 = new HashMap<>();
        int count=0;
        for(String st : words1){
            map.put(st,map.getOrDefault(st,0)+1);
        }
        for(String str: words2){
            if(map.containsKey(str)){
                map2.put(str,map2.getOrDefault(str,0)+1);
            }
        }
        for (Map.Entry<String,Integer> mapElement : map2.entrySet()) {
            if(mapElement.getValue()==1 && map.get(mapElement.getKey())==1){
                count++;
            }
        }
        return count;
    }
}