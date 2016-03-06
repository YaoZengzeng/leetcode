/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    struct ListNode *oddPre,*oddCur,*even;
    if(head==NULL||head->next==NULL){
        return head;
    }
    
    oddPre=head;
    even=oddPre->next;
    while(even&&even->next){
        oddCur=even->next;
        even->next=oddCur->next;
        even=even->next;
        oddCur->next=oddPre->next;
        oddPre->next=oddCur;
        oddPre=oddPre->next;
    }
    
    return head;
}
