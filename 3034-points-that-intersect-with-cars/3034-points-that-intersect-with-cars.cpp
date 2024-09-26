class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
       set<int> st;
       for(vector<int> num:nums){
        int start = num[0];
        int end = num[1];
        for(int i=start;i<=end;i++){
            st.insert(i);
        }
       }
    //    int count =0;
       for (auto it = st.begin(); it != 
                          st.end(); ++it)
        cout << ' ' << *it;

       return st.size();
    }
};