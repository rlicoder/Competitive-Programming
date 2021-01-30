/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
LLNode* solve(LLNode* node) {
    LLNode* ret = new LLNode;
    LLNode* head = ret;
    if (!node)
    {
        return NULL;
    }
    else
    {
        ret->val = node->val;
    }

    int count = 0;
    int skip = ret->val;
    while (node->next)
    {
        count++;
        node = node->next;
        if (count == skip)
        {
            ret->next = new LLNode;
            ret = ret->next;
            ret->val = node->val;
            count = 0;
            skip = ret->val;
        }
    }
    return head;
}
