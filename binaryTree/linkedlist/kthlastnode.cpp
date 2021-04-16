/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
int solve(LLNode *node, int k)
{
    int l = 0;
    if (!node)
        return 0;
    LLNode *temp = node;
    while (temp)
    {
        l++;
        temp = temp->next;
    }
    cout << l;
    temp = node;
    int go = l - k;
    if (go == 1)
        return node->val;
    for (int i = 0; i < l - k - 1; i++)
    {
        temp = temp->next;
    }
    return temp->val;
}