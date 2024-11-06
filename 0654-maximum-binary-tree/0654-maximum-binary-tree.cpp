/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums,0,nums.size()-1);
    }
    TreeNode* build(vector<int>& nums,int start,int end){
        if(start>end) return nullptr;
        int maxi=findmax(nums,start,end);
        TreeNode* root= new TreeNode(maxi);
        int i = giveIndex(nums,maxi,start,end);
        root->left = build(nums,start,i-1);
        root->right=build(nums,i+1,end);
        return root;

    }
    int findmax(vector<int>& nums,int start,int end){
        int maxi=INT_MIN;
        for(int i=start;i<=end;i++){
            maxi=max(maxi,nums[i]);
        }
        return maxi;
    }
    int giveIndex(vector<int>& nums,int target,int start,int end){
        for(int i=start;i<=end;i++){
            if(nums[i]==target) return i;
        }
        return -1;
    }
};