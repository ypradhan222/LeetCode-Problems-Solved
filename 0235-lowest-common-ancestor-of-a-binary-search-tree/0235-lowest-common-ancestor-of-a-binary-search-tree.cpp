/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if(root==p || root==q) return root;
         TreeNode* leftval;
        //   TreeNode* rightval;
        if(root->val <p->val && root->val <q->val ){
            leftval= lowestCommonAncestor(root->right,p,q);
        }
        else if(root->val >  p->val && root->val > q->val){
            leftval = lowestCommonAncestor(root->left,p,q);
        }
        return leftval;
    }
};