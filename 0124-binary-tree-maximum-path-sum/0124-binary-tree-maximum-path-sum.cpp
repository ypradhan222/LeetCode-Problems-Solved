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
    int maxsum;
    int maxPathSum(TreeNode* root) {
        maxsum=INT_MIN;
        solve(root);
        return maxsum;
    }
    int solve(TreeNode* root){
        if(!root) return 0;
        int l=solve(root->left);
        int r=solve(root->right);
        int included=l+r+root->val;
        int only_lr=max(l,r)+root->val;
        int only_root =root->val;
        maxsum=max({maxsum,included,only_lr,only_root});
        return max(only_lr,only_root);
    }
};