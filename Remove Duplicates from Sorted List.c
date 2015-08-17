/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* p;
    int pre;
    
    if(head==NULL){
        return head;
    }
    
    p=head;
    pre=head->val;
    
    while(p->next!=NULL){
        if(p->next->val==pre){
            p->next=p->next->next;
        }else{
            pre=p->next->val;
            p=p->next;
        }
    }
    
    return head;
}
