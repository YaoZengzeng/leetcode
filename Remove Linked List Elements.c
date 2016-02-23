/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* p;
    while(head&&head->val==val){
        head=head->next;
    }
    if(head==NULL){
        return NULL;
    }
    
    p=head;
    while(p->next){
        if(p->next->val==val){
            p->next=p->next->next;
            continue;
        }
        p=p->next;
    }
    
    return head;
}
