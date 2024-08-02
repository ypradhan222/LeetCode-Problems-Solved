class Solution {
    public int sumOfUnique(int[] nums) {
        HashMap<Integer,Integer> map = new HashMap<>(); 
        for(int num: nums){
            map.put(num,map.getOrDefault(num,0)+1);
        }
        int sum=0;
        for(Map.Entry<Integer,Integer> el : map.entrySet()){
            if(el.getValue() == 1){
                sum+=el.getKey();
            }
        }
        return sum;
    }
}