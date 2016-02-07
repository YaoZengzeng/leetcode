/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root) {
    struct TreeNode *t;
    if(root==NULL){
        return;
    }
    if(root->left!=NULL && root->right !=NULL){
        flatten(root->left);
        flatten(root->right);
        t=root->left;
        while(t->right){
            t=t->right;
        }
        t->right=root->right;
        root->right=root->left;
        root->left=NULL;
    }else if(root->left!=NULL && root->right==NULL){
        flatten(root->left);
        root->right=root->left;
        root->left=NULL;
    }else if(root->left==NULL && root->right!=NULL){
        flatten(root->right);
    }
    
    return;
}
