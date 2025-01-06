class Solution {
public:
    string truncateSentence(string s, int k) {
       string result = "";
        for (int i = 0, count = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                count++;
                if (count == k)
                    return result;
            }
            result += s[i];
        }
        return result;
    }
};