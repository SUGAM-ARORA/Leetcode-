class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int res = 0;
        while(head!=NULL){
            int val = head->val;
            res=res*2 + val;
            head=head->next;
        }
        return res;
    }
};
