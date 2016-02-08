/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    struct ListNode *beg,*pre,*cur,*first,*next;
    int i;
    
    if(m==n){
        return head;
    }
    
    cur=head;
    for(i=2;i<m;i++){
        cur=cur->next;
    }
    if(m!=1){
        beg=cur;
        first=pre=cur->next;
        cur=cur->next;
    }else{
        first=pre=cur;
    }
    cur=cur->next;
    next=cur->next;
    for(i=0;i<n-m;i++){
        cur->next=pre;
        pre=cur;
        cur=next;
        if(next!=NULL){
            next=next->next;
        }
    }
    if(m!=1){
        beg->next=pre;
        first->next=cur;
        return head;
    }else{
        first->next=cur;
        return pre;
    }
    
}
