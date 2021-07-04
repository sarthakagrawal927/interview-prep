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
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> ans;
        if (!root)
            return ans;
        while (q.size())
        {
            vector<int> curr;
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                if (temp)
                {
                    if (temp->left)
                        q.push(temp->left);
                    if (temp->right)
                        q.push(temp->right);
                    curr.push_back(temp->val);
                }
            }
            ans.push_back(curr);
        }
        return ans;
    }
};