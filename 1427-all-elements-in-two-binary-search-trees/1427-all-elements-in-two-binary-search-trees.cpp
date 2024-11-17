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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> l1;
        vector<int> l2;
        vector<int> res;
        if(!root1 && !root2) return {};
        inorder(root1,l1);
        inorder(root2,l2);
        merge(l1,l2,res);
        return res;

    }
    void inorder(TreeNode* root,vector<int>& res){
        if(!root) return;
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }
   void merge(vector<int>& l1,vector<int>&l2,vector<int>& res){
        int i=0,j=0;
        while(i<l1.size() && j<l2.size()){
            if(l1[i]<l2[j]){
                res.push_back(l1[i++]);
            }
            else{
                res.push_back(l2[j++]);
            }
        }
            while(i<l1.size()){
                res.push_back(l1[i++]);
            }
            while(j<l2.size()){
                res.push_back(l2[j++]);
            }
    }
};