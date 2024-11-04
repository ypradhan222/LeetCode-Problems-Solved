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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int ind=0;
        return solve(preorder,inorder,0,preorder.size()-1,ind);
    }
    TreeNode* solve(vector<int>& preorder,vector<int>& inorder,int start,int end,int& idx){
        if(start>end) return nullptr;
        int val=preorder[idx];
        int i=start;
        for(;i<=end;i++){
            if(inorder[i]==val) break;
        }
        idx++;
        TreeNode* root = new TreeNode(val);
        root->left= solve(preorder,inorder,start,i-1,idx);
        root->right= solve(preorder,inorder,i+1,end,idx);
        return root;
    }
};