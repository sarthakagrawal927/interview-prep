// inverting bt
// iterative
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *work, *temp;
        while (q.size())
        {
            work = q.front();
            q.pop();
            if (work)
            {
                temp = work->left;
                work->left = work->right;
                work->right = temp;
                q.emplace(work->left);
                q.emplace(work->right);
            }
        }
        return root;
    }
};

TreeNode *invertTree(TreeNode *root)
{
    if (!root)
        return;
    swap(left, right);
    invertTree(left);
    invertTree(right);
}