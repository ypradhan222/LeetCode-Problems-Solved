// class Solution {
// public:
//     int mySqrt(int x) {
//         if(x==0) return 0;
//         int left=1,right=x;
//         while(left<=right){
//             int mid=(left+right)/2;
//             int m_s=mid*mid;
//             if(m_s==x){
//                 return mid;
//             }
//             else if(m_s<x){
//                 left=mid+1;
//             }
//             else right=mid-1;
//         }
//         return right;
//     }
// };
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int left = 1, right = x;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid == x / mid) {
                return mid;
            } else if (mid < x / mid) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
};