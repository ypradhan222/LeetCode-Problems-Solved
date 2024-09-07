class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // sort(nums.begin(),nums.end()); //NlogN
        // int prev = nums[0];
        // int maxlen=1;
        // int len=1;
        // for(int i=1;i<nums.size();i++){
        //     if(nums[i]==prev) continue;
        //     if(nums[i]==prev+1){
        //         len++;
        //     }
        //     else{len =1;}
        //     prev=nums[i];
        //     maxlen=max(maxlen,len);
        // }
        // return maxlen;
        unordered_set<int> st;
        for(int num:nums){
            st.insert(num);
        }
        int maxlen=0;
        for(auto it = st.begin();it!=st.end();it++){
            int prev= *it -1;
            if(!st.contains(prev)){
                int len=1;
                int next= *it+1;
                while(st.contains(next)){
                    len++;
                    next++;
                }
                maxlen=max(maxlen,len);
            }
            // cout << *it <<endl;
        }
        return maxlen;
    }
};