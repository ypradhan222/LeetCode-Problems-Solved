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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr) return true;
        if (root == nullptr || subRoot == nullptr) return false;
        if (root->val == subRoot->val) {
            if (sameTree(root, subRoot)) {
                return true;
            }
        }
        if (root->left != nullptr) {
            if (isSubtree(root->left, subRoot)) {
                return true;
            }
        }
        if (root->right != nullptr) {
            if (isSubtree(root->right, subRoot)) {
                return true;
            }
        }
        return false;
    }

    bool sameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        else if (p->val == q->val) {
            return sameTree(p->left, q->left) && sameTree(p->right, q->right);
        }
        
        return false;
    }
};
