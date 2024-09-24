/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*,Node*> mp;
        return cloneIt(node,mp);

    }
    Node* cloneIt(Node* node,unordered_map<Node*,Node*>& mp){
        Node* newnode = new Node(node->val);
        mp[node]= newnode;
        for(auto neighbor:node->neighbors){
            if(mp.find(neighbor)==mp.end()){
                (newnode->neighbors).push_back(cloneIt(neighbor,mp));
            }
            else{
                (newnode->neighbors).push_back(mp[neighbor]);
            }
        }
        return newnode;

    }
};