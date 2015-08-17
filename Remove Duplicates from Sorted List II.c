/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *p,*t,*p1,*p2;
    int val;
    if(head==NULL||head->next==NULL){
        return head;
    }
    
    p=head->next;
    while(p!=NULL&&head->val==p->val){
        val=head->val;
        while(p!=NULL&&p->val==val){
            p=p->next;
        }
        head=p;
        if(head==NULL){
            return head;
        }else{
            p=head->next;
        }
    }
    
    t=head;
    
    while(t->next!=NULL){
        p1=p2=t->next;
        val=p1->val;
        
        while(p2->next!=NULL&&p2->next->val==val){
            p2=p2->next;
        }
        if(p1==p2){
            t=t->next;
        }else{
            t->next=p2->next;
        }
    }
    
    return head;
    
}
