class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int count=1;
        vector<int> res(nums.size()-k+1,-1);
        for(int i=1;i<k;i++){
            if(nums[i]==nums[i-1]+1){
                count++;
            }
            else count=1;
        }
        if(count==k) res[0]=nums[k-1];
        int i=1;int j=k;
        while(j<nums.size()){
            if(nums[j]==nums[j-1]+1){
                count++;
            }
            else count=1;
            if(count>=k) res[i]=nums[j];
            i++;j++;
        }
        return res;
    }
};