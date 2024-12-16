class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n=nums.size();
        vector<pair<int,int>> vec(n);
        for(int i=0;i<n;i++){
            vec[i]={nums[i],i};
        }
        make_heap(vec.begin(),vec.end(),greater<>());
        while(k--){
            pop_heap(vec.begin(),vec.end(),greater<>());
            pair<int,int> temp=vec.back();
            vec.pop_back();
            int idx=temp.second;
            int no=temp.first;
            nums[idx]=no*multiplier;
            vec.push_back({nums[idx],idx});
            push_heap(vec.begin(),vec.end(),greater<>());

        }
        return nums;

    }
};