class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int res=INT_MAX;
        int n=size(cookies);
        vector<int> children(k,0);
        backtrack(0,cookies,children,k,res,n);
        return res;
    }
    void backtrack(int idx,vector<int>& cookies,vector<int>& children,int k,int& res,int n){
        if(idx>=n){
            int unfair=*max_element(begin(children),end(children));
            res=min(res,unfair);
            return;
        }
        for(int i=0;i<k;i++){
            children[i]+=cookies[idx];
            backtrack(idx+1,cookies,children,k,res,n);
            children[i]-=cookies[idx];
        }
    }
};