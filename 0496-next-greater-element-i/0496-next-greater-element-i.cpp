class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        unordered_map<int,int> mp;
        vector<int> res;
        for(int num:nums2){
            while(!stk.empty() && stk.top()<num){
                mp[stk.top()]=num;
                stk.pop();
            }
            stk.push(num);
        }
        for(int num:nums1){
            if(mp.find(num)!=mp.end()){
                res.push_back(mp[num]);
            }
            else res.push_back(-1);
        }
        return res;
    }
};