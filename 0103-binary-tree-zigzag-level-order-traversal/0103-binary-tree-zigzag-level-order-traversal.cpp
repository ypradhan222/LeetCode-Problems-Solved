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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue<TreeNode*> que;
        que.push(root);
        bool flag = true;
        while (!que.empty()) {
            vector<int> vec;
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* curr = que.front();
                que.pop();
                if (flag) {
                    vec.push_back(curr->val); 
                } else {
                    vec.insert(vec.begin(), curr->val); 
                }
                if (curr->left) que.push(curr->left);
                if (curr->right) que.push(curr->right);
            }
            flag = !flag;
            res.push_back(vec);
        }
        return res;
    }
};
