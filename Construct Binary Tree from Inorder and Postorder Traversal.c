/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    struct TreeNode *root;
    int i;
    
    if(inorderSize==0) {
        return NULL;
    }
    root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val=postorder[postorderSize-1];
    
    i=0;
    while(inorder[i]!=postorder[postorderSize-1]){
        i++;
    }
    
    root->left=buildTree(inorder,i,postorder,i);
    root->right=buildTree(inorder+i+1,inorderSize-1-i,postorder+i,inorderSize-1-i);
    
    return root;
}
