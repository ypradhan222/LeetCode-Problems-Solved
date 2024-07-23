class Solution {
    public int[] frequencySort(int[] nums) {
        HashMap<Integer,Integer> map = new HashMap<>();
        for(int num:nums){
            map.put(num,map.getOrDefault(num,0)+1);
        }
        List<Map.Entry<Integer, Integer>> entryList = new ArrayList<>(map.entrySet());
        entryList.sort((e1, e2) -> {
            int freqCompare = e1.getValue().compareTo(e2.getValue());
            if (freqCompare != 0) {
                return freqCompare;
            } else {
                return e2.getKey().compareTo(e1.getKey());
            }
        });
        int[] result = new int[nums.length];
        int index = 0;
        for (Map.Entry<Integer, Integer> entry : entryList) {
            int number = entry.getKey();
            int frequency = entry.getValue();
            for (int i = 0; i < frequency; i++) {
                result[index++] = number;
            }
        }

        return result;

    }
}
