/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* sortList2(struct ListNode* head,int n) {
    int i,cnt;
    struct ListNode* p=head,*q,*t,*ret;
    
    if(n==1||n==0){
        return head;
    }
    
    for(i=0; i<n/2-1; i++){
        p=p->next;
    }
    t=p->next;
    p->next=NULL;
    
    p = sortList2(head,n/2);
    q = sortList2(t,n-n/2);
    
    if(p->val>q->val){
        t=q;
        q=p;
        p=t;
    }
    
    ret=p;
    while(q){
        if(p->next==NULL){
            p->next=q;
            break;
        }
        if(p->next->val > q->val){
            t=q->next;
            q->next=p->next;
            p->next=q;
            q=t;
        }
        p=p->next;
    }
    
    return ret;
}

struct ListNode* sortList(struct ListNode* head) {
   int n=0;
   struct ListNode *p=head;
   while(p){
       n++;
       p=p->next;
   }
   return sortList2(head,n);
   
}
