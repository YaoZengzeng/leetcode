/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    int left,right;
    
    if(root==NULL){
        return 0;
    }
    
    left=minDepth(root->left);
    right=minDepth(root->right);
    
    if(left==0){
        return right+1;
    }else if(right==0){
        return left+1;
    }else{
        return left<right ? left+1 : right+1;
    }
    
}
