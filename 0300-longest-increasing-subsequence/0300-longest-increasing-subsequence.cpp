class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
         res.push_back(nums[0]); 
        for(int i=1;i<size(nums);i++){
            if(res.back()<nums[i]){
                res.push_back(nums[i]); 
            }
            else{
                int ind=bSearch(res,nums[i]);
                res[ind]= nums[i];
            }
        }
        return res.size();
    }
    int bSearch(vector<int>& nums,int target){
        int i=0;int j=size(nums)-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]==target){
                return mid;
            
            }
            else if(nums[mid]<target){
                i=mid+1;

            }
            else j=mid-1;
        }
        return i;
    }
};