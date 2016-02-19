/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *p,*q;
    
    if(head==NULL){
        return false;
    }
    p=q=head;
    
    while(1){
        if(p){
            p=p->next;
        }else{
            return false;
        }
        
        if(q){
            q=q->next;
        }else{
            return false;
        }
        
        if(q){
            q=q->next;
        }else{
            return false;
        }
        
        if(p==q){
            return true;
        }
    }
    
}
