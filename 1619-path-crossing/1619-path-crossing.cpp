class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> st;
        pair<int,int> x;
        x.first=0;x.second=0;
        st.insert(x);
        for(auto& s:path){
            if(s=='N'){
                x.second+=1;
                // st.insert(x);
            }
            else if(s=='S'){
                x.second--;
                
            }
            else if(s=='E'){
                x.first++;
            }
            else {
                x.first--;
            }
            if(st.find(x)!=st.end()){
                return true;
            }
            st.insert(x);
            
        }
        return false;
    }
};