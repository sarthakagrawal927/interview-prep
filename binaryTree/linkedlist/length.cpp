/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
int solve(LLNode *node)
{
    int l = 0;
    if (!node)
        return l;
    while (node)
    {
        l++;
        node = node->next;
    }
    return l;
}