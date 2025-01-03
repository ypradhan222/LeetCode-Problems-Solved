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
    int sumRootToLeaf(TreeNode* root) {
        string s = "";
        dfs(root, s);
        int sum = 0;
        for(string& binary : res) {
            sum += stoi(binary, nullptr, 2);
        }
        return sum;
    }
    
    void dfs(TreeNode* root, string& temp) {
        if(!root) return;
        temp += to_string(root->val);
        if(!root->left && !root->right) {
            res.push_back(temp);
        }
        dfs(root->left, temp);
        dfs(root->right, temp);
        temp.pop_back();
    }
};
