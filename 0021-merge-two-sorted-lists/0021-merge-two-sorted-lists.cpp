/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* L1, ListNode* L2) {
        if(L1 == NULL)
        {
            return L2;
        }
        if(L2 == NULL)
        {
            return L1;
        }
        if (L1 -> val <= L2 -> val)
        {
            L1-> next = mergeTwoLists(L1 -> next, L2);
            return L1;
        }
        else
        {
            L2 -> next = mergeTwoLists(L1, L2 -> next);
            return L2;
        }
    }
};