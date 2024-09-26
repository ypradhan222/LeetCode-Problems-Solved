class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n= matrix.size();
        int midIndex= (k-1);
        int start= matrix[0][0];
        int end= matrix[n-1][n-1];
        while(start<=end){
            int mid= start+(end-start)/2;
            int lesser= findSmaller(matrix,mid);
            if(lesser<=midIndex){
                start= mid+1;
            }
            else end= mid-1;
        }
        return start;
    }
    int findSmaller(vector<vector<int>>& matrix,int mid){
        int count=0;
        for(int i=0;i<matrix.size();i++){
            int start=0;
            int end= matrix[i].size()-1;
            while(start<=end){
                int mid1= start+(end-start)/2;
                if(matrix[i][mid1]<=mid){
                    start=mid1+1;
                }
                else end=mid1-1;
            }
            count+=start;
        }
        return count;
    }
};