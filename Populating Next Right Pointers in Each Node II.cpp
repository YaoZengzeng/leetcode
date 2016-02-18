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
        vector<int> level;
        addr.push_back(root);
        level.push_back(1);
        
        int i=0;
        while(i<addr.size()){
            if(addr[i]->left!=NULL){
                addr.push_back(addr[i]->left);
                level.push_back(level[i]+1);
            }
            if(addr[i]->right!=NULL){
                addr.push_back(addr[i]->right);
                level.push_back(level[i]+1);
            }
            i++;
        }
        
        
        for(int i=0;i<addr.size()-1;i++){
            if(level[i]!=level[i+1]){
                addr[i]->next=NULL;
                continue;
            }
            addr[i]->next=addr[i+1];
        }
        addr[addr.size()-1]->next=NULL;
    }
};
