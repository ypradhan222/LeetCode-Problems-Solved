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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> que;
        if(!root) return 0;
        que.push(root);
        int res=0;
        int level=0;
        while(!que.empty()){
            int sum=0;
            int size=que.size();
            for(int i=0;i<size;i++){
                TreeNode* curr=que.front();
                que.pop();
                if(curr->left) que.push(curr->left);
                if(curr->right) que.push(curr->right);
                sum+=curr->val;
                
            }
            res=sum;
        }
        return res;
    }
};