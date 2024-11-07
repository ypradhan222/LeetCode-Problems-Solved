class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> mp;
        for(int num:arr){
            mp[num]++;
        }
        int maxi=-1;
        for(auto it=mp.rbegin();it!=mp.rend();it++){
            if(it->first==it->second&& it->first>maxi){
                maxi=it->first;
            }
        }
        return maxi;
    }
};