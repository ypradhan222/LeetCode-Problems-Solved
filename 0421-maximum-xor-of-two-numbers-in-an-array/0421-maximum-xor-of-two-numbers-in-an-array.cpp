class Solution {
public:
    struct trieNode{
        trieNode* left;
        trieNode* right;
    };
    void insert(trieNode* root,int num){
        trieNode* curr=root;
        for(int i=31;i>=0;i--){
            int ith_bit =(num>>i)&1;
            if(ith_bit==0){
                if(!curr->left){
                    curr->left=new trieNode();
                }
                curr=curr->left;
            }
            else{
                if(!curr->right){
                    curr->right=new trieNode();
                }
                curr=curr->right;
            }
        }
    }
    int findMax(trieNode* root,int &num){
        int maxi=0;
        trieNode* curr=root;
        for(int i=31;i>=0;i--){
            int ith_bit =(num>>i)&1;
            if(ith_bit==1){
                if(curr->left){
                    maxi +=pow(2,i);
                    curr=curr->left;
                }
                else{
                    curr=curr->right;
                }
            }
            else{
                if(curr->right){
                    maxi +=pow(2,i);
                    curr=curr->right;
                }
                else{
                    curr=curr->left;
                }
            }
        }
        return maxi;
    }
    int findMaximumXOR(vector<int>& nums) {
        trieNode* root=new trieNode();
        for(int &num:nums){
            insert(root,num);
        }    
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            int temp =findMax(root,nums[i]);
            maxi=max(maxi,temp);
        }
        return maxi;
    }
};