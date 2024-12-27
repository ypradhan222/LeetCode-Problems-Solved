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
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int maxlevel=0;
        int level=0;
        int maxi=INT_MIN;
        while(!que.empty()){
            int size=que.size();
            int sum=0;
            for(int i=0;i<size;i++){
                TreeNode* curr= que.front();
                que.pop();
                sum+=curr->val;
                if(curr->left) que.push(curr->left);
                if(curr->right) que.push(curr->right);
            }
            level++;
            if(sum>maxi){
                maxi=sum;
                maxlevel=level;
            }

        }
        return maxlevel;
    }
};