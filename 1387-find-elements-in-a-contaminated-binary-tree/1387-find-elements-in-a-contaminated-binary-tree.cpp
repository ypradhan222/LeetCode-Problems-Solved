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
class FindElements {

public:
    void recover(TreeNode* root){
        if(!root) return ;
        // root->val=0;
        if(root->left){
            root->left->val=2*root->val+1;
            s.insert(root->left->val);
            recover(root->left);
        }
        if(root->right){
            root->right->val=2*root->val+2;
            s.insert(root->right->val);
            recover(root->right);
        }
    }
    TreeNode* root;
    unordered_set<int> s;
    FindElements(TreeNode* root){
        root->val=0;
        recover(root);
        this->root = root;
        s.insert(0);
    }
    bool find(int target) {
        if(s.count(target)){
            return true;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */