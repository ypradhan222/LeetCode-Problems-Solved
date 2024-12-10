class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        bool containsOne=false;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                containsOne=true;
            }
            if(nums[i]<=0 || nums[i]>n){
                nums[i]=1;
            }
        }
        if(containsOne==false) return 1;
        for(int i=0;i<n;i++){
            int num=abs(nums[i]);
            int idx=num-1;
            if(nums[idx]<0) continue;
            nums[idx]*=-1;
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0) return i+1;
        }
        return n+1;
    }
};