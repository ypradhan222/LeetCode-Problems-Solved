class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       vector<int> count(1001,0);
       unordered_set<int> result;
       for(int num:nums1){
        count[num]++;
       }
       for(int num:nums2){
        if(count[num]>0){
            result.insert(num);
            count[num]--;
        }
       }
        vector<int> res(result.begin(),result.end());
        return res;
    }
};