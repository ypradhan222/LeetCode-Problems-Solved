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
    int countNodes(TreeNode* root) {
        queue<TreeNode*> que;
        if(!root) return 0;
        que.push(root);
        int count=0;
        while(!que.empty()){
            int size=que.size();
            for(int i=0;i<size;i++){
                TreeNode* curr=que.front();
                que.pop();
                count++;
                if(curr->left) que.push(curr->left);
                if(curr->right) que.push(curr->right);
            }
        }
        return count;
    }
};