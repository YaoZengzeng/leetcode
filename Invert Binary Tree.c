/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    struct TreeNode* t;
    if(root==NULL){
        return NULL;
    }
    invertTree(root->left);
    invertTree(root->right);
    t=root->left;
    root->left=root->right;
    root->right=t;
    
    return root;
}
