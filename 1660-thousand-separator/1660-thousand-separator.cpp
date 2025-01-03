class Solution {
public:
    string thousandSeparator(int n) {
        string s=to_string(n);
        if(s.size()<=3){
            return s;
        }
        for(int i=s.size();i>=1;i=i-3)
        {
            if(i==s.size())continue;
            else s.insert(i, ".");
        }
        return s;

    }
};