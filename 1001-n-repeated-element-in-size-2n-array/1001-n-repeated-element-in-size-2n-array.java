class Solution {
    public int repeatedNTimes(int[] nums) {
        HashMap<Integer,Integer> map = new HashMap<>();
        for(int num:nums){
            map.put(num,map.getOrDefault(num,0)+1);
        }
        for(Map.Entry<Integer,Integer> etr:map.entrySet()){
            if(etr.getValue()== nums.length/2){
                return etr.getKey();
            }
        }
        return 0;
    }
}