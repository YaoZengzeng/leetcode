/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
int* addr[10000];
int cnt;

void preorder(struct TreeNode *root) {
    if(root==NULL){
        return;
    }
    preorder(root->left);
    addr[cnt++]=&(root->val);
    preorder(root->right);
    
    return;
}

void recoverTree(struct TreeNode* root) {
    int a1,a2,i;
    cnt=0;
    preorder(root->left);
    addr[cnt++]=&(root->val);
    preorder(root->right);
    if(*addr[0]>*addr[1]){
        a1=0;
    }else{
        for(i=1;i<cnt-1;i++){
            if(*addr[i]>*addr[i-1]&&*addr[i]>*addr[i+1]){
                a1=i; 
                break;
            }
        }
    }
    
   if(*addr[cnt-1]<*addr[cnt-2]){
        a2=cnt-1;
    }else{
        for(i=cnt-2;i>0;i--){
            if(*addr[i]<*addr[i-1]&&*addr[i]<*addr[i+1]){
                a2=i;
                break;
            }
        }
    }
    
    i=*addr[a1];
    *addr[a1]=*addr[a2];
    *addr[a2]=i;
    
    return;
}
