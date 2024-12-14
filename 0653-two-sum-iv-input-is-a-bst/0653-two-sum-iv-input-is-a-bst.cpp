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
    bool findTarget(TreeNode* root, int k) {
        vector<int> res;
        inorder(root,res);
        int left=0;
        int right=res.size()-1;
        while(left<right){
            if(res[left]+res[right]==k) return true;
            else if(res[left]+res[right]<k){
                left++;
            }
            else right--;
        }
        return false;
    }
    void inorder(TreeNode* root,vector<int>& res){
        if(!root) return;
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }
};