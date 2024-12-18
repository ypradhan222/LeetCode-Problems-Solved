class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int,int> mp;
        for(int& num:candyType){
            mp[num]++;
        }
        int count=0;
        for(auto it:mp){
        count++;
        }
        if(candyType.size()/2 >= count){
            return count;
        }
        else return candyType.size()/2;
    }
};