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
    vector<string> res;
    int sumNumbers(TreeNode* root) {
        string s="";
        int ans=0;
        if (!root) return 0;
        dfs(root, s);
        for (int i = 0; i < res.size(); i++) {
            ans += stoi(res[i]);
        }
        return ans;
    }
    void dfs(TreeNode* root, string temp) {
        if (!root) return;
        temp += to_string(root->val);
        if (!root->left && !root->right) {
            res.push_back(temp);
            return;
        }
        dfs(root->left, temp);
        dfs(root->right, temp);
    }
};
