/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
int solve(LLNode *node)
{
    int s = 0;
    while (node != NULL)
    {
        s = s * 2 + node->val;
        node = node->next;
    }
    return s;
}