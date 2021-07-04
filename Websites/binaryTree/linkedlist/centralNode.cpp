/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
int solve(LLNode *node)
{
    LLNode *slow = node;
    LLNode *fast = node;

    if (node->next == NULL)
        return node->val;
    if (node->next->next == NULL)
        return node->next->val;

    while (slow->next != NULL && fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast->next == NULL)
        return slow->val;
    return slow->next->val;
}