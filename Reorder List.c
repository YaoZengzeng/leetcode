/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
struct ListNode* reorder(struct ListNode* head,int n) {
    struct ListNode *end,*t;
    if(n==1){
        t=head->next;
        head->next=NULL;
        return t;
    }
    if(n==2){
        t=head->next->next;
        head->next->next=NULL;
        return t;
    }
    
    end=reorder(head->next,n-2);
    t=end->next;
    end->next=head->next;
    head->next=end;
    
    return t;
}

void reorderList(struct ListNode* head) {
    struct ListNode *p;
    int n=0;
    
    if(head==NULL){
        return ;
    }
    while(p){
        n++;
        p=p->next;
    }
    reorder(head,n);
    
    return ;
}
