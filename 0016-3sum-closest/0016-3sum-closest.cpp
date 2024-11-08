class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
     int n= nums.size();
     int closest=10000000;
     sort(begin(nums),end(nums));
     for(int i=0;i<n-2;i++){
        int left=i+1;
        int right=n-1;
        while(left<right){
            int sum= nums[i]+nums[left]+nums[right];
            if(abs(target-sum)<abs(target-closest)){
                closest=sum;
            }
            if(sum<target)
                left++;
            else right--;
        }
     }
     return closest;
    }
};