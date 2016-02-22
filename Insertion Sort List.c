/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode *p,*q;
    int t;
    if(head==NULL || head->next==NULL){
        return head;
    }
    
    p=head;
    while(p){
        q=head;
        while(q!=p){
            if(q->val>p->val){
                break;
            }else{
                q=q->next;
            }
            
        }
        if(q!=p){
            while(q!=p){
                t=p->val;
                p->val=q->val;
                q->val=t;
                q=q->next;
            }
        }
        p=p->next;
    }
    return head;
}
