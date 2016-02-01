/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    int     d1=0,d2=0;
    if(root==NULL) {
        return 0;
    }
    if(root->left!=NULL) {
        d1=maxDepth(root->left);
    }
    if(root->right!=NULL) {
        d2=maxDepth(root->right);
    }
    
    return d1>d2?d1+1:d2+1;
}
