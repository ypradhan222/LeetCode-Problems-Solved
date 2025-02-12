class Solution {
public:
    int getDigitSum(int num){
        int sum=0;
        while(num>0){
            sum+=(num%10);
            num/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int n= size(nums);
        int result=-1;
        int mp[82]={0}; //cuz maximum sum of digits can be 81 
        for(int i=0;i<n;i++){
            int digitsum=getDigitSum(nums[i]);
            if(mp[digitsum]>0){
                result=max(mp[digitsum]+nums[i],result);
            }
            mp[digitsum]=max(mp[digitsum],nums[i]);
        }
        return result;
    }
};