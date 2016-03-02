/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int countNodes(struct TreeNode* root) {
    int l=0,r=0;
    struct TreeNode* p;
    if(root==NULL){
        return 0;
    }
    
    p=root;
    while(p){
        l++;
        p=p->left;
    }
    p=root;
    while(p){
        r++;
        p=p->right;
    }
    
    if(l==r){
        return (1<<l)-1;
    }
    
    return 1+countNodes(root->left)+countNodes(root->right);
    
}
