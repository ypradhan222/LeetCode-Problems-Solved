/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> que;
        vector<vector<int>> res;
        if(!root) return res;
        que.push(root);
        while(!que.empty()){
            vector<int> temp;
            int size= que.size();
            for(int i=0;i<size;i++){
                Node* curr = que.front();
                que.pop();
                temp.push_back(curr->val);
                for(Node* child:curr->children){
                    que.push(child);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};