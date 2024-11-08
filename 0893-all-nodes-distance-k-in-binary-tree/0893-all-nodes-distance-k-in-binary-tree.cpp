/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> mp;
    void inorder(TreeNode* root){
        if(!root) return;
        if(root->left){
            mp[root->left]=root;
        }
        inorder(root->left);
        if(root->right){
            mp[root->right]=root;
        }
        inorder(root->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        inorder(root);
        bfs(target,k,res);
        return res;
    }
    void bfs(TreeNode* target,int k,vector<int>& res){
        queue<TreeNode*> que;
        que.push(target);
        unordered_set<int> visited;
        visited.insert(target->val);
        while(!que.empty()){
            int size = que.size();
            if(k==0) break;
            for(int i=0;i<size;i++){
                TreeNode* curr=que.front();
                que.pop();
                if(curr->left && !visited.count(curr->left->val)) {que.push(curr->left);
                visited.insert(curr->left->val);
                }
                if(curr->right && !visited.count(curr->right->val)) {que.push(curr->right);
                visited.insert(curr->right->val);
                }
                if(mp.count(curr) && !visited.count(mp[curr]->val)) {que.push(mp[curr]);
                visited.insert(mp[curr]->val);
                }
            }
                k--;
        }
        while(!que.empty()){
            TreeNode* temp= que.front();
            que.pop();
            res.push_back(temp->val);
        }
        
    }
};