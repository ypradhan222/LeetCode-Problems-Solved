class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long res=0;
        int n=size(nums);
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            int diff= nums[i]-i;
            int total=i;
            int good = mp[diff];
            res+=(total-good);
            mp[diff]++;
        }
        return res;
    }
};