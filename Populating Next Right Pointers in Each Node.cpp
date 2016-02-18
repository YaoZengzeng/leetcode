/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL){
            return;
        }
        vector<TreeLinkNode*> addr;
        
        addr.push_back(root);
        
        int i=0;
        while(i<addr.size()){
            if(addr[i]->left!=NULL){
                addr.push_back(addr[i]->left);
            }
            if(addr[i]->right!=NULL){
                addr.push_back(addr[i]->right);
            }
            i++;
        }
        
        int k=1;
        for(int i=0;i<addr.size();i++){
            if((i+1)==((1<<k)-1)){
                k++;
                continue;
            }
            addr[i]->next=addr[i+1];
        }
    }
};
