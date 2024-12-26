class Solution {
public:
    int countPrimes(int n) {
      return seive(n);
    }
    int seive(int n){
        vector<bool> vec(n+1,true);
        int count=0;
        for(int i=2;i*i<=n;i++){
            if(vec[i]==true){
                for(int j=i*i;j<=n;j+=i){
                    vec[j]=false;
                }
            }
            
        }
        for(int i=2;i<n;i++){ 
            if(vec[i]) count++;}

        return count;
    }
};