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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> que;
        if(root==nullptr) return 0;
        int level=0;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            for(int i=0;i<size;i++){
                if(que.front()->left == nullptr && que.front()->right ==nullptr){
                    return level+1;
                }
                if(que.front()->left!=nullptr){
                    que.push(que.front()->left);
                }
                if(que.front()->right!=nullptr){
                    que.push(que.front()->right);
                }
            que.pop();
            }
            level++;
        }
        return level+1;
    }
};