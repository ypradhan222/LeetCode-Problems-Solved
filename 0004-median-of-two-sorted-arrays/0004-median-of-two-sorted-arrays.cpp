class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=size(nums1);
        int n=size(nums2);
        vector<int> res(m+n);
        int i=0;
        int j=0;
        int k=0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                res[k++]=nums1[i++];
            }
            else{
                res[k++]=nums2[j++];
            }
        }
        while(i<m){
            res[k++]=nums1[i++];
        }
        while(j<n){
            res[k++]=nums2[j++];
        }
        cout<<res[size(res)/2];
        if(size(res)%2!=0){
            return res[ceil(size(res)/2)];
        }
        else{
            return (double)(res[size(res)/2]+res[(size(res)/2)-1])/2;
        }
    }
};