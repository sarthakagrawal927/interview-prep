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
    bool help(TreeNode *root, long int minV, long int maxV)
    {
        if (!root)
            return true;
        if (root->val <= minV || root->val >= maxV)
            return false;
        return help(root->left, minV, root->val) && help(root->right, root->val, maxV);
    }
    bool isValidBST(TreeNode *root)
    {
        return help(root, -3 * pow(2, 30), (pow(2, 31)));
    }
};