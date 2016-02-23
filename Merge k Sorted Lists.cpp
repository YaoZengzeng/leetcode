/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* merge2Lists(ListNode* l1,ListNode* l2) {
        
        if(l2==NULL){
            return l1;
        }
        if(l1==NULL){
            return l2;
        }
        if(l1->val > l2->val){
            ListNode* t=l1;
            l1=l2;
            l2=t;
        }
        
        ListNode *ans=l1;
        while(l2){
            if(l1->next==NULL){
                l1->next=l2;
                return ans;
            }
            if(l2->val < l1->next->val){
                ListNode *t=l2->next;
                l2->next=l1->next;
                l1->next=l2;
                l2=t;
            }
            l1=l1->next;
        }
        
        return ans;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        
        int n=lists.size();
        while(n>1){
            for(int i=0;i<n/2;i++){
                lists[i]=merge2Lists(lists[i],lists[n-i-1]);
            }
            n%2 ? n=n/2+1 : n=n/2;
        }
        
        return lists[0];
    }
};
