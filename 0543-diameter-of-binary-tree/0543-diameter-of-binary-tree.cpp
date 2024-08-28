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
    int diameterOfBinaryTree(TreeNode* root) {
        int result=0;
        findDepth(root,result);
        return result;
    }
    int findDepth(TreeNode* root,int& result){
        if(root==nullptr){
            return 0;
        }
        int leftsubtree= findDepth(root->left,result);
        int rightsubtree = findDepth(root->right,result);
        result = max(result,leftsubtree+rightsubtree);
        return (1+max(leftsubtree,rightsubtree));
    }
};