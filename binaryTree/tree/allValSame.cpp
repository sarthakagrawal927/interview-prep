/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
bool solve(Tree *root)
{
    if (!root)
        return true;

    if (root->left)
    {
        if (root->left->val != root->val)
            return false;
    }
    if (root->right)
    {
        if (root->right->val != root->val)
            return false;
    }

    return solve(root->left) && solve(root->right);
}