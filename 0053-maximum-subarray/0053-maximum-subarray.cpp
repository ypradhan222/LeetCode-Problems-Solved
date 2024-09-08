class Solution
{
    public:
        int maxSubArray(vector<int>& nums){
            return maxSubArrayHelper(nums,0,nums.size()-1);
            
        }
        int maxSubArrayHelper(vector<int> &nums, int left, int right)
        {
            if (left == right)
            {
                return nums[left];
            }

            int mid = (left + right) / 2;
            int leftSum = maxSubArrayHelper(nums, left, mid);
            int rightSum = maxSubArrayHelper(nums, mid + 1, right);
            int crossSum = findCrossSubarray(nums, left, mid, right);
            if (leftSum >= rightSum && leftSum >= crossSum)
            {
                return leftSum;
            }
            else if (rightSum >= leftSum && rightSum >= crossSum)
            {
                return rightSum;
            }
            else return crossSum;
           	// int left=0;int right=1;
           	// int sum =0;
           	// while(right < nums.size()){
           	//     if(nums[left]>nums[right]){
           	//     int intersum = nums[left]+nums[right];
           	//     cout<<intersum<<endl;
           	//     sum=max(sum,intersum);
           	//     }
           	//     else {left = right;}
           	//     right++;
           	// }
           	// return sum;
        }
    int findCrossSubarray(vector<int> &nums, int left, int mid, int right)
    {
        int leftSum = INT_MIN;
        int sum = 0;
        for (int i = mid; i >= left; i--)
        {
            sum += nums[i];
            if (sum > leftSum)
            {
                leftSum = sum;
               	// maxleft =i
            }
        }
        int rightSum = INT_MIN;
        int sum1 = 0;
        for (int i = mid + 1; i <= right; i++)
        {
            sum1 += nums[i];
            if (sum1 > rightSum)
            {
                rightSum = sum1;
               	// maxright=i;
            }
        }
        return leftSum + rightSum;
    }
};