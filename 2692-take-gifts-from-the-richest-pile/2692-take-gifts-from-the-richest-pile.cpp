class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(),gifts.end());
        long long sum=0;
        for(int& num:gifts){
            sum+=num;
        }
        long long mysum=0;
        while(k--){
            int maxi=pq.top();
            pq.pop();
            int remaining = sqrt(maxi);
            mysum+=(maxi-remaining);
            pq.push(remaining);
        }
        return sum-mysum;
    }
};