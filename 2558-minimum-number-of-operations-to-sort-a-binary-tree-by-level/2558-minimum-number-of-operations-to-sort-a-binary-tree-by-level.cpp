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
    int swapsMini(vector<int>& vec){
        int swaps=0;
        vector<int> sortedVec(vec.begin(),vec.end());
        sort(sortedVec.begin(),sortedVec.end());
        unordered_map<int,int> mp;
        for(int i=0;i<vec.size();i++){
            mp[vec[i]]=i;
        }
        for(int i=0;i<vec.size();i++){
            if(vec[i]==sortedVec[i]) continue;
            int curridx=mp[sortedVec[i]];
            mp[vec[i]]=curridx;
            mp[vec[curridx]]=i;
            swap(vec[curridx],vec[i]);
            swaps++;
        }
        return swaps;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int result=0;
        while(!que.empty()){
            int size=que.size();
            vector<int> vec;
            for(int i=0;i<size;i++){
                TreeNode* curr= que.front();
                que.pop();
                vec.push_back(curr->val);
                if(curr->left) que.push(curr->left);
                if(curr->right) que.push(curr->right);
            }
            result+=swapsMini(vec);
        }
        return result;
    }
};