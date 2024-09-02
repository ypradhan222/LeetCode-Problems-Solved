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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp="";
        traverse(root,temp,ans);
        return ans;
    }
    void traverse(TreeNode* root,string temp,vector<string>& ans){
        if(root==nullptr){
            return ;
        }
        if(root->left==nullptr && root->right==nullptr){
            temp+=to_string(root->val);
            ans.push_back(temp );
        }
        temp+=to_string(root->val);
        temp+="->";
        traverse(root->left,temp,ans);
        traverse(root->right,temp,ans);
    } 
};