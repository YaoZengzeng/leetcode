/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    int l[1000],ge[1000];
    int lCnt,geCnt,i;
    struct ListNode *p=head;
    lCnt=geCnt=0;
    
    while(p!=NULL){
        if(p->val<x){
            l[lCnt++]=p->val;
        }else{
            ge[geCnt++]=p->val;
        }
        p=p->next;
    }
    
    p=head;
    
    for(i=0;i<lCnt;i++){
        p->val=l[i];
        p=p->next;
    }
    
    for(i=0;i<geCnt;i++){
        p->val=ge[i];
        p=p->next;
    }
    
    return head;

}
