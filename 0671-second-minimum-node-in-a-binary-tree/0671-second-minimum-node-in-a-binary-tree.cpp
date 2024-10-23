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
    int findSecondMinimumValue(TreeNode* root) {
        int secondMin = dfs(root, root->val);
        return secondMin;
    }
    
    int dfs(TreeNode* root, int minVal) {
        if (!root) return -1; 

        if (root->val > minVal) {
            return root->val; 
        }
    
        int leftSecondMin = dfs(root->left, minVal);
        int rightSecondMin = dfs(root->right, minVal);
        if (leftSecondMin != -1 && rightSecondMin != -1) {
            return min(leftSecondMin, rightSecondMin);
        }
    
        return leftSecondMin != -1 ? leftSecondMin : rightSecondMin;
    }
};