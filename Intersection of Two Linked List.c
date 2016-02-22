/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *findIntersectionNode(struct ListNode *head) {
    struct ListNode *first,*second;
    
    first=second=head;
    do{
        first=first->next->next;
        second=second->next;
    }while(first!=second);
    
    first=head;
    while(first!=second){
        first=first->next;
        second=second->next;
    }
    
    return first;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *end,*p;
    int trueFlag;
    
    if(headA==NULL || headB==NULL){
        return NULL;
    }
    
    p=headA;
    while(p->next){
        p=p->next;
    }
    end=p;
    p->next=headA;
    
    trueFlag=0;
    p=headB;
    while(p){
        if(p==headA){
            trueFlag=1;
            break;
        }
        p=p->next;
    }
    if(trueFlag==0){
        end->next=NULL;
        return NULL;
    }
    
    p=findIntersectionNode(headB);
    
    end->next=NULL;
    
    return p;
}
