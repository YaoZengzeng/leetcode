/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *pGroup[100000],*p,*pre,*post;
    int num=0,first=1,i;
    
    if(k<=1){
        return head;
    }
    
    p=pre=head;
    while(p!=NULL){
        pGroup[num++]=p;
        p=p->next;
        if(num==k){
            if(first){
                head=pre=pGroup[k-1];
                for(i=0;i<k-1;i++){
                    pre->next=pGroup[k-2-i];
                    pre=pre->next;
                }
                pre->next=p;
                first=0;
            }else{
                for(i=0;i<k;i++){
                    pre->next=pGroup[k-1-i];
                    pre=pre->next;
                }
                pre->next=p;
            }
            num=0;
        }
    }
    return head;
}
