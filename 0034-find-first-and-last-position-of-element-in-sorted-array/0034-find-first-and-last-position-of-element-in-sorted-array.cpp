class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       int n=size(nums);
       int leftmost=search1(nums,target,n);
       int rightmost=search2(nums,target,n);
       return {leftmost,rightmost}; 
    }
    int search1(vector<int>& nums,int target,int n){
        int low=0;int high=n-1;
        int leftmost=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                leftmost=mid;;
                high=mid-1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else low=mid+1;
        }
        return leftmost;
    }
    int search2(vector<int>& nums,int target,int n){
        int low=0;int high=n-1;
        int rightmost=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                rightmost=mid;;
                low=mid+1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else low=mid+1;
        }
        return rightmost;
    }
};