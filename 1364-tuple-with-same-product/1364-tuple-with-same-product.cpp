class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=size(nums);
        int count=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int prod =nums[i]*nums[j];
                mp[prod]++;
            }
        }
        for(auto& it:mp){
            int p=it.second;
            count+=(p*(p-1)/2);
        }
        return count*8;
    }
};