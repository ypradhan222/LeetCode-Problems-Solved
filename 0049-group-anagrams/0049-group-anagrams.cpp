class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> mp;
        for(string& str:strs){
            string s=str;
            sort(begin(str),end(str));
            mp[str].push_back(s);
        }
        for(auto& it:mp){
            res.push_back(it.second);
        }
        return res;
    }
};