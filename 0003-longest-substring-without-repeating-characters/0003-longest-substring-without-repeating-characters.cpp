class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int maxLength=0;
        int i=0;int j=0;
        while(j<s.size()){
            auto  it= st.find(s[j]);
            if(it==st.end()){
                if(j-i+1>maxLength){
                    maxLength=j-i+1;
                } 
                    st.insert(s[j]);
                    j++;
            }
             else{
                    st.erase(s[i]);
                    i++;
                }


        }
        return maxLength;
    }
};