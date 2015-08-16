struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *p,*pre;
    int i;
    if(n==0){
        return head;
    }
    pre=p=head;
    for(i=0;i<n;i++) p=p->next;
    if(p==NULL){
        head=head->next;
        return head;
    }
    
    while(p->next!=NULL){
        pre=pre->next;
        p=p->next;
    }
    
    pre->next=pre->next->next;
    return head;
}
