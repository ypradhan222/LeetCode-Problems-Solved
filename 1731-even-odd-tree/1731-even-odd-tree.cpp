/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        bool isEvenOddTree(TreeNode *root)
        {
            if (!root) true;
            queue<TreeNode*> que;
            que.push(root);
            int level=0;
            while (!que.empty())
            {
                int size = que.size();
                int prevValue = (level % 2 == 0) ? INT_MIN : INT_MAX;
                for (int i = 0; i < size; i++)
                {
                    TreeNode *curr = que.front();
                    que.pop();
                    int value = curr->val;
                    if (level % 2 == 0)
                    {
                        if (value % 2 == 0 || value <= prevValue)
                            return false;
                    }
                    else
                    {
                        if (value % 2 != 0 || value >= prevValue)
                            return false;
                    }
                    prevValue = value;
                    if (curr->left) que.push(curr->left);
                    if (curr->right) que.push(curr->right);
                }
                level++;
            }
            return true;
        }
};