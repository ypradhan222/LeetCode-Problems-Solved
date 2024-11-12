class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(begin(strs),end(strs));
        string first=strs[0];
        string last=strs[strs.size()-1];
        string res;
        for(int i=0;i<first.size();i++){
            if(first[i]!=last[i]){
                break;
            }
            res.push_back(first[i]);
        }
        return res;
    }
};