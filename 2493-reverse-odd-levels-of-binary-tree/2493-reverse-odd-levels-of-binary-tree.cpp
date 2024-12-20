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
    TreeNode* reverseOddLevels(TreeNode* root) {
        invert(root->left,root->right,2);
        return root;

    }
    void invert(TreeNode* lefttree,TreeNode* righttree,int curr_level){
        if(!lefttree && !righttree) return;
        if(curr_level%2==0){
            swap(lefttree->val,righttree->val);
        }
        invert(lefttree->left,righttree->right,curr_level+1);
        invert(lefttree->right,righttree->left,curr_level+1);
    }
};