/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
LLNode *solve(LLNode *node, int target)
{
    while (node->val == target)
    {
        node = node->next;
    }

    LLNode *temp = node->next;
    LLNode *prev = node;

    while (temp && temp->next)
    {
        if (temp->val == target)
        {
            prev->next = temp->next;
            temp = temp->next;
        }
        else
        {
            temp = temp->next;
            prev = prev->next;
        }
    }
    if (temp && temp->val == target)
        prev->next = NULL;

    return node;
}