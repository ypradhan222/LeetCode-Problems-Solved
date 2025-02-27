class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums){
        unordered_map<int,int> mp;
        for(int& num:nums){
            mp[num]++;
        }
        vector<int> res;
        for(auto& x:mp){
            if(x.second>1){
                res.push_back(x.first);
            }
        }
        return res;
    }
};