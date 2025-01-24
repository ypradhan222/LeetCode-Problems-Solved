class Solution {
public:
    int trap(vector<int>& height) {
        int n=size(height);
        //Storing max element on left and right for each index
        vector<int> leftmax=getLeftMax(height,n);
        vector<int> rightmax=getRightMax(height,n);
        int sum=0;
        for(int i=0;i<n;i++){
            int h=min(rightmax[i],leftmax[i])-height[i];
            sum+=h;
        }
        return sum;
        
    }
    vector<int> getLeftMax(vector<int>& height,int n){
        vector<int> res(n);
        res[0]=height[0];
        for(int i=1;i<n;i++){
            res[i]=max(res[i-1],height[i]);
        }
        return res;
    }
     vector<int> getRightMax(vector<int>& height,int n){
        vector<int> res(n);
        res[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            res[i]=max(res[i+1],height[i]);
        }
        return res;
    }
};