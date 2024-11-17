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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int maxi=INT_MIN;
            int size =que.size();
            for(int i=0;i<size;i++){
                TreeNode* curr= que.front();
                que.pop();
                maxi=max(maxi,curr->val);
                if(curr->left) que.push(curr->left);
                if(curr->right) que.push(curr->right);
            }
            res.push_back(maxi);
        }
        return res;
    }
};