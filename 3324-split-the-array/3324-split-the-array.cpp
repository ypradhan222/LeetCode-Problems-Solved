class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        vector<int> count(101,0);
        for(int num:nums){
            count[num]++;
            if(count[num]>2) return false;
        }
        return true;
    }
};