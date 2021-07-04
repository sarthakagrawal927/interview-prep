/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
pair<int, int> solveH(Tree *root)
{
    pair<int, int> p;
    if (!root)
    {
        p.first = p.second = 0;
        return p;
    }
    if (root->left || root->right)
    {
        p.first = 0;
        p.second = 1;
    }
    else
    {
        p.first = 1;
        p.second = 0;
    }
    pair<int, int> leftA = solveH(root->left);
    pair<int, int> rightA = solveH(root->right);

    p.first += leftA.first + rightA.first;
    p.second += leftA.second + rightA.second;

    return p;
}
vector<int> solve(Tree *root)
{
    vector<int> a;
    pair<int, int> p = solveH(root);
    a.push_back(p.first);
    a.push_back(p.second);
    return a;
}