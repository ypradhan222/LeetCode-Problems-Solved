class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        HashMap<Integer,Integer> map= new HashMap<>();
        for(int i=1;i<=nums.length;i++){
            map.put(i,-1);
        }
        for(int num:nums){
            map.put(num,num);
        }
        List<Integer> list = new ArrayList<>();
        for(int i=1;i<=nums.length;i++){
            if(map.get(i)==-1){
                list.add(i);
            }
        }
        return list;
    }
}