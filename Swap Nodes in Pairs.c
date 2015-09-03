/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* p=head;
    int t;
    while(p!=NULL&&p->next!=NULL){
        t=p->val;
        p->val=p->next->val;
        p->next->val=t;
        p=p->next->next;
    }
    
    return head;
}
