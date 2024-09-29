class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n= arr.size();
        int start=0,end=n-1;
        while(start<=end){
            int mid= start+(end-start)/2;
            if(arr[mid]>arr[mid+1] && arr[mid-1]<arr[mid]){
                return mid;
            }
            else if(arr[mid]>arr[mid-1]){
                start=mid;
            }
            else end = mid;
        }
        return start;
    }
};