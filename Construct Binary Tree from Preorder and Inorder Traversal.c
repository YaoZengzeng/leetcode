/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    struct TreeNode *root;
    int     i;
    
    if(preorderSize==0) {
        return NULL;
    }
    
    root=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val=preorder[0];
    
    i=0;
    while(inorder[i]!=preorder[0]){
        i++;
    }
    
    root->left=buildTree(preorder+1,i,inorder,i);
    
    root->right=buildTree(preorder+1+i,preorderSize-1-i,inorder+1+i,preorderSize-1-i);

    
    return root;
}    
