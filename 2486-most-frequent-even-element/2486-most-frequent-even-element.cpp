class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int> map;
        for(int num:nums){
            if(num%2==0) ++map[num];
        }
        if(map.empty()) return -1;
        int mostFrequent = -1;
        int maxFrequency = 0;
        
        for (auto& [num, freq] : map) {
            if (freq > maxFrequency || (freq == maxFrequency && num < mostFrequent)) {
                mostFrequent = num;
                maxFrequency = freq;
            }
        }
        
        return mostFrequent;
    }
};