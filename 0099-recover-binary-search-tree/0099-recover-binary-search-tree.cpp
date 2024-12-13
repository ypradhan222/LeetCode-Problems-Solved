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
    int i=0;
    void recoverTree(TreeNode* root) {
        vector<int> res;
        inorder(root,res);
        sort(res.begin(),res.end());
        docheck(root,res);

    }
    void inorder(TreeNode* root,vector<int>& res){
        if(!root) return ;
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
        
    }
    void docheck(TreeNode* root,vector<int>& res){
        if(!root) return;
        docheck(root->left,res);
        if(res[i]!=root->val){
            swap(res[i],root->val);
        }
        i++;
        docheck(root->right,res);
    }
};