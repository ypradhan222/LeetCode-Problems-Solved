/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        bool isValidBST(TreeNode *root)
        {
           	// if(!root) return true;
           	// if(!root->left && !root->right) return true;
           	// if(root->val< root->left->val && root->val>root->right->val) return false;
           	// return isValidBST(root->left) || isValidBST(root->right);
            vector<int> res ;
            inorder(root, res);
            for (int i = 1; i < res.size(); i++)
            {
                if (res[i - 1] >= res[i]) return false;
            }
            return true;
        }
    void inorder(TreeNode *root, vector<int> &res)
    {

        if (!root) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
};