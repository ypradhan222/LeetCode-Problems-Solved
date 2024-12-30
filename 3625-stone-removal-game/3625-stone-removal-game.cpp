class Solution {
public:
    bool canAliceWin(int n) {
        int pick = 10;
        int count = 0;
        while (pick > 0 && pick <= n) {
            n -= pick;
            count++;
            pick--;
        }
        return count % 2 != 0;
    }
};
