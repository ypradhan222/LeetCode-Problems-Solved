class Solution {
public:
    string frequencySort(string s) {
      unordered_map<char,int> mp;
      for(char& c:s){
        mp[c]++;
      }
      string result="";
      vector<pair<char,int>> vec(mp.begin(),mp.end());
      sort(vec.begin(),vec.end(),sortValue);
       for(auto& p:vec){
            while(p.second!=0){
                result+=p.first;
                p.second--;
            }
       }
      return result;
    }
    static bool sortValue(pair<char,int>& a,pair<char,int>& b){
        return a.second > b.second;
    }
};