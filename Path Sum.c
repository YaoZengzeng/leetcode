/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int sum) {
    if(root==NULL) {
        return false;
    }
    
    if(root->left==NULL && root->right==NULL && sum-root->val==0) {
        return true;
    }
    
    if(root->left && hasPathSum(root->left,sum-root->val)) {
        return true;
    }
    if(root->right && hasPathSum(root->right,sum-root->val)) {
        return true;
    }
    
    return false;
}
