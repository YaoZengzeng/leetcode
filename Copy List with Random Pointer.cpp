/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        map<RandomListNode*,int> addrToIdx;
        map<int,RandomListNode*> idxToAddr;
        RandomListNode *ans,*p,*q;
        
        if(head==NULL){
            return NULL;
        }
        
        ans=new RandomListNode(head->label);
        addrToIdx.insert(pair<RandomListNode*,int>(head,0));
        idxToAddr.insert(pair<int,RandomListNode*>(0,ans));
        
        p=head,q=ans;
        for(int i=1;;i++){
            p=p->next;
            if(p==NULL){
                q->next=NULL;
                break;
            }
            q->next=new RandomListNode(p->label);
            q=q->next;
            q->label=p->label;
            addrToIdx.insert(pair<RandomListNode*,int>(p,i));
            idxToAddr.insert(pair<int,RandomListNode*>(i,q));
        }
        
        p=head,q=ans;
        while(q){
            if(p->random==NULL){
                q->random=NULL;
            }else{
                q->random=idxToAddr[addrToIdx[p->random]];
            }
            p=p->next;
            q=q->next;
        }
        
        return ans;
        
    }
};
