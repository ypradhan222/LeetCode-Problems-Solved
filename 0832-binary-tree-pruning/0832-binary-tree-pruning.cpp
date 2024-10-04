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
    TreeNode* pruneTree(TreeNode* root) {
        if(root==nullptr) return nullptr;
        // if(!isPresent(root->left)) root->left=nullptr;
        // if(!isPresent(root->right)) root->right=nullptr;
        root->left =pruneTree(root->left);
        root->right =pruneTree(root->right);
        if(!root->left && !root->right && root->val==0){
            return nullptr;
        }
        
        return root;
    }
    // bool isPresent(TreeNode* root){
    //     if(root==nullptr) return false;
    //     if(root->val==1){
    //         return true;
    //     }
    //     return isPresent(root->left)||isPresent(root->right);
    // }
};