/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    int i,j,flag;
    int n=0;
    struct ListNode *pre,*cur,*post;
    struct ListNode *p=head;
    while(p){
        n++;
        p=p->next;
    }
    if(n<=1){
        return true;
    }else if(n==2){
        if(head->val==head->next->val){
            return true;
        }else{
            return false;
        }
    }
    
    pre=head;
    for(i=0;i<n/2;i++){
        pre=pre->next;
    }
    cur=pre->next;
    post=cur->next;
    for(i=0;i<(n-1)/2;i++){
        cur->next=pre;
        pre=cur;
        cur=post;
        if(post){
            post=post->next;
        }
    }
    
    flag=1;
    p=pre;
    for(i=0;i<n/2;i++){
        if(head->val==p->val){
            head=head->next;
            p=p->next;
        }else{
            flag=0;
            break;
        }
    }
    
    
    cur=pre;
    pre=NULL;
    post=cur->next;
    for(i=0;i<(n-1)/2;i++){
        cur->next=pre;
        pre=cur;
        cur=post;
        post=post->next;
    }
    
    if(flag){
        return true;
    }else{
        return false;
    }
    
}
