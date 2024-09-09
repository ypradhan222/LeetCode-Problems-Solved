class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // if(nums.size()==1) return nums[0];
        // int currprod=1;
        // int maxProd = INT_MIN;
        // for(int i=0;i<nums.size();i++){ //O(N)
        //     currprod = max(nums[i],currprod*nums[i]);
        //     maxProd = max(maxProd,currprod);
            
        // }
        // return maxProd;
        return maxProdHelper(nums,0,nums.size()-1);
    }
    int maxProdHelper(vector<int>& nums,int left,int right){
        if(left==right){
            return nums[left];
        }
        
            int mid = (left+right)/2;
            int leftProd = maxProdHelper(nums,left,mid);
            int rightProd = maxProdHelper(nums,mid+1,right);
            int crossPrd = maxCross(nums,left,mid,right);
            if(leftProd>=rightProd && leftProd>=crossPrd){
                return leftProd;
            }
            else if(rightProd>=leftProd && rightProd>=crossPrd){
                return rightProd;
            }
            else return crossPrd;
        
    }
    int maxCross(vector<int>& nums,int left,int mid,int right){
        int maxProd = INT_MIN;
        int leftProdMin = INT_MAX;
        int prod =1;
        for(int i=mid;i>=left;i--){
            prod = prod*nums[i];
            if(prod>maxProd){
                maxProd=prod;
            }
            if(prod<leftProdMin){
                leftProdMin = prod;
            }
        }
        int rightProd = INT_MIN;
        int rightProdMin = INT_MAX;
         prod=1;
        for(int i=mid+1;i<=right;i++){
            prod*=nums[i];
            if(prod>rightProd){
                rightProd = prod;
            }
            if(prod< rightProdMin){
                rightProdMin = prod;
            }
        }
        return max(maxProd*rightProd,leftProdMin*rightProdMin);
    }
};