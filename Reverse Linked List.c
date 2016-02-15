/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    int v[10000];
    int cnt;
    struct ListNode* p;
    
    p=head;
    while(p){
        v[cnt++]=p->val;
        p=p->next;
    }
    
    p=head;
    while(cnt>0){
        p->val=v[--cnt];
        p=p->next;
    }
    
    return head;
}
