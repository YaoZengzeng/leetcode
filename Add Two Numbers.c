/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry=0;
    struct ListNode *p1,*p2,*head,*p;
    if(l1==NULL){
        return l2;
    }
    if(l2==NULL){
        return l1;
    }
    
    head=(struct ListNode*)malloc(sizeof(struct ListNode));
    head->val=(l1->val+l2->val)%10;
    carry=(l1->val+l2->val)/10;
    p1=l1->next,p2=l2->next;
    p=head;
    
    while(p1!=NULL&&p2!=NULL){
        p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
        p->next->val=(p1->val+p2->val+carry)%10;
        carry=(p1->val+p2->val+carry)/10;
        p=p->next;
        p1=p1->next;
        p2=p2->next;
    }
    
    while(p1!=NULL){
        p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
        p->next->val=(p1->val+carry)%10;
        carry=(p1->val+carry)/10;
        p=p->next;
        p1=p1->next;
    }
    
    while(p2!=NULL){
        p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
        p->next->val=(p2->val+carry)%10;
        carry=(p2->val+carry)/10;
        p=p->next;
        p2=p2->next;
    }

    if(carry){
        p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
        p->next->val=carry;
        p=p->next;
    }
    
    p->next=NULL;
    
    return head;
}
