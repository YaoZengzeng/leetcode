/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    int n=0,i;
    struct ListNode *p=head,*last;
    
    if(head==NULL||head->next==NULL){
        return head;
    }
    
    while(p){
        if(p->next==NULL){
            last=p;
        }
        p=p->next;
        n++;
    }
    
    last->next=head;
    k=k%n;
    
    p=head;
    for(i=1;i<n-k;i++){
        p=p->next;
    }
    
    last=p->next;
    p->next=NULL;
    
    return last;
    
}
