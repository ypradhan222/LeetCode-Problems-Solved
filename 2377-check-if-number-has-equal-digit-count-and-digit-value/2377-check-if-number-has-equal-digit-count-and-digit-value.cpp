class Solution {
public:
    bool digitCount(string num) {
        vector<int> count(10,0);
        for(int i=0;i<num.size();i++){
            count[num[i]-'0']++;
            
        }
        for(int i=0;i<num.size();i++){
            cout<<count[i];
            if(count[i]==(num[i]-'0')) continue; else return false;
        }
        return true;
    }
};