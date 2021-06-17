/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

int solveH(Tree *root)
{
    if (!root)
        return 0;

    if (root->left || root->right)
    {
        if (!(root->left && root->right))
            return 1 + solveH(root->left) + solveH(root->right);
        else
            return solveH(root->left) + solveH(root->right);
    }
    return 0;
}
int solve(Tree *root)
{
    return solveH(root);
}