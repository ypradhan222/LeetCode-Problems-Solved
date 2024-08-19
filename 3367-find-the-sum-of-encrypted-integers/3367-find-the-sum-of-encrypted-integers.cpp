class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum=0;
        for(int num: nums){
            int maxdig=0;
            int temp=0;
            int count=0;
            while(num>0){
                if(num%10 > maxdig){
                    maxdig=num%10;
                }
                num/=10;
                count++;
            }
            while(count){
                temp=temp*10+maxdig;
                count--;
            }
            cout<< num<<endl;
            sum+=temp;
            }
        return sum;
    }
    
};