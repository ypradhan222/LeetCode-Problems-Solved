class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> res;
        vector<int> arr1,arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i=2;i<nums.size();i++){
            if(arr1.back() > arr2.back()){
                arr1.push_back(nums[i]);
            }
            else arr2.push_back(nums[i]);
        }
        res=arr1;
        for(auto num:arr2){
            res.push_back(num);
        }
        return res;

    }
};