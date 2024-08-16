class Solution {
public:
    string removeDuplicates(string s) {
        string str ="";
        for(int i=0;i<s.length();i++){
            if(str.empty()){
                str.push_back(s.at(i));
            }
            else if(str.back()==s.at(i)){
                str.pop_back();
            }
            else str.push_back(s.at(i));
        }
        return str;
    }
};