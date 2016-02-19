/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *p,*q,*t;
    
    if(head==NULL){
        return NULL;
    }
    p=q=head;
    
    while(1){
        if(p){
            p=p->next;
        }else{
            return NULL;
        }
        
        if(q){
            q=q->next;
        }else{
            return NULL;
        }
        
        if(q){
            q=q->next;
        }else{
            return NULL;
        }
        
        if(p==q){
            break;
        }
    }

    
    t=head;
    
    
    while(1){
        if(t==q){
            return q;
        }
        p=p->next;
        while(p!=q){
            if(t==p){
                return p;
            }
            p=p->next;
        }
        t=t->next;
    }
}
