/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    int val1[1000],val2[1000],val[2000];
    int num1=0,num2=0,num,i,j,t;
    struct ListNode *p1=l1,*p2=l2;
    
    if(l1==NULL){
        return l2;
    }else if(l2==NULL){
        return l1;
    }
    
    val1[num1++]=p1->val;
    while(p1->next!=NULL){
        val1[num1++]=p1->next->val;
        p1=p1->next;
    }
    
    val2[num2++]=p2->val;
    while(p2->next!=NULL){
        val2[num2++]=p2->next->val;
        p2=p2->next;
    }
    
    p1->next=l2;
    
    if(val1[0]>val1[num1-1]){
        for(i=0;i<num1/2;i++){
            t=val1[i];
            val1[i]=val1[num1-1-i];
            val1[num1-1-i]=t;
        }
    }
    
    if(val2[0]>val2[num2-1]){
        for(i=0;i<num2/2;i++){
            t=val2[i];
            val2[i]=val2[num2-1-i];
            val2[num2-1-i]=t;
        }
    }
    
    i=j=num=0;
    while(i<num1&&j<num2){
        if(val1[i]<val2[j]){
            val[num++]=val1[i++];
        }else{
            val[num++]=val2[j++];
        }
    }
    
    if(i<num1){
        while(i<num1){
            val[num++]=val1[i++];
        }
    }else{
        while(j<num2){
            val[num++]=val2[j++];
        }
    }
    
    p1=l1;
    i=0;
    while(p1!=NULL){
        p1->val=val[i++];
        p1=p1->next;
    }
    
    return l1;
}
