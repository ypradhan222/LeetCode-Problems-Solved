class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
       vector<int> ind;
       for(int i=0;i<size(s1);i++){
        if(s1[i]!=s2[i]){
            ind.push_back(i);
        }
        if(size(ind)>2) return false;
       } 
       if(size(ind)==2){
        int x=ind.front();
        int y=ind.back();
        return s1[x]==s2[y] && s2[x]==s1[y];
       }
       return size(ind)==0;
    }
};