class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
    //Using Set
    //    set<int> st;
    //    for(vector<int> num:nums){
    //     int start = num[0];
    //     int end = num[1];
    //     for(int i=start;i<=end;i++){
    //         st.insert(i);
    //     }
    //    }
    // //    int count =0;
    //    for (auto it = st.begin(); it != 
    //                       st.end(); ++it)
    //     cout << ' ' << *it;

    //    return st.size();
    
    //Using counting
    vector<int> freq(102,0);
    for(vector<int> num:nums){
        int start = num[0];
        int end = num[1];
        freq[start]++;
        freq[end+1]--;
    }
    int count=0;
    for(int i=1;i<freq.size();i++){
        freq[i]+=freq[i-1];
        if(freq[i]>0) count++;
    }
    return count;
    }
};