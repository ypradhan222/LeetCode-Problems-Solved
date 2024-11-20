class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=*max_element(piles.begin(),piles.end());
        int left=1;
        int right=maxi;
        int res=1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(canEat(piles,h,mid)){
                res=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        return res;
    }
    bool canEat(vector<int>& piles,int h,int ind){
        long long actual=0;
        for(int num:piles){
            actual+=(long long)(num + ind - 1) / ind;
            if (actual > h) return false;
        }
        return actual<=h;
    }
};