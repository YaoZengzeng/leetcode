/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isBalanced(struct TreeNode* root) {
    int t;
    if(root==NULL){
        return true;
    }
    if(isBalanced(root->left)&&isBalanced(root->right)) {
        if(root->left!=NULL&&root->right!=NULL){
            t=root->left->val-root->right->val;
            if(t>=-1&&t<=1) {
                root->val = root->left->val > root->right->val?root->left->val+1 : root->right->val+1;\
                return true;
            }else{
                return false;
            }
        }else if(root->left!=NULL && root->right==NULL) {
            if(root->left->val!=1){
                return false;
            }else{
                root->val=2;
                return true;
            }
        }else if(root->right!=NULL && root->left==NULL) {
            if(root->right->val!=1){
                return false;
            }else{
                root->val=2;
                return true;
            }
        }else{
            root->val=1;
            return true;
        }
    }else{
        return false;
    }
}
