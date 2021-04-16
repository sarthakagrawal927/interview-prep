/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
#include <queue>
queue<Tree *> a;
LLNode *solve(Tree *root)
{
    LLNode *node = new LLNode();
    LLNode *t2;
    t2 = node;
    a.push(root);
    while (a.size() > 0)
    {
        Tree *temp = a.front();
        a.pop();
        cout << temp->val;
        LLNode *t = new LLNode();
        t->val = temp->val;
        t2->next = t;
        t2 = t2->next;
        if (temp->left)
            a.push(temp->left);
        if (temp->right)
            a.push(temp->right);
    }
    return node->next;
}