class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* NEXT = node->next;
        node->val = NEXT->val;
        node->next = NEXT->next;
    }
};
