/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        long long kthLargestLevelSum(TreeNode *root, int k)
        {
            queue<TreeNode*> que;
            que.push(root);
            vector < long long > res;
            while (!que.empty())
            {
                int size = que.size();
                long long sum = 0.0f;
                for (int i = 0; i < size; i++)
                {
                    TreeNode *curr = que.front();
                    que.pop();
                    sum += curr->val;
                    if (curr->left) que.push(curr->left);
                    if (curr->right) que.push(curr->right);
                }
                res.push_back(sum);
            }
            if (res.size() < k) return -1;
            sort(begin(res), end(res), greater < long long > ());
            return res[k - 1];
        }
};