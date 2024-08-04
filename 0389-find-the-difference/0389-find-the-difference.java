import java.util.HashMap;

class Solution {
    public char findTheDifference(String s, String t) {
        HashMap<Character, Integer> map = new HashMap<>();
        for (char c : t.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }
        for (char c : s.toCharArray()) {
            if (map.containsKey(c)) {
                int count = map.get(c) - 1;
                if (count == 0) {
                    map.remove(c);
                } else {
                    map.put(c, count);
                }
            }
        }
        for (char c : map.keySet()) {
            return c;
        }
        return '\0';
    }
}
