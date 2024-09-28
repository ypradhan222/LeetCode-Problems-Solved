class Solution {
public:
    bool checkRecord(string s) {
        int countA = 0; 
        int countL = 0;  
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'P') {
                countL = 0;
                continue;
            }
            else if (s[i] == 'A') {
                countA++;
                countL = 0; 
                if (countA >= 2) { 
                    return false;
                }
            }
            else if (s[i] == 'L') {
                countL = 1; 
                for (int j = i + 1; j < i + 3 && j < s.length(); j++) {
                    if (s[j] == 'L') {
                        countL++;
                    } else {
                        break; 
                    }
                }
                if (countL >= 3) { 
                    return false;
                }
            }
        }
        return true;
    }
};
