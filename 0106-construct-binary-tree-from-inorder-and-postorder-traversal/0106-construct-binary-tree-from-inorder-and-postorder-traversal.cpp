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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return solve(inorder,postorder,0,inorder.size()-1,0,inorder.size()-1);
    }
    TreeNode* solve(vector<int>& inorder,vector<int>& postorder,int start,int end,int postart,int postend){
        if(start>end) return nullptr;
        int val= postorder[postend];
        TreeNode* root = new TreeNode(val);
         int i=start;
        for(;i<=end;i++){
            if(inorder[i]==val) break;
        }
       int leftsize=i-start;
       int rightsize=end-i;
        root->left= solve(inorder,postorder,start,i-1,postart,postart+leftsize-1);
        root->right= solve(inorder,postorder,i+1,end,postend-rightsize,postend-1);
        return root;
    }
};