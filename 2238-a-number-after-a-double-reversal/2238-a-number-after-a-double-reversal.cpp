class Solution {
public:
    bool isSameAfterReversals(int num) {
        string s=to_string(num);
        reverse(s.begin(),s.end());
        int num2=stoi(s);
        string str=to_string(num2);
        reverse(str.begin(),str.end());
        num2=stoi(str);
        return num==num2;
    }
};