/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void kthSmallestDfs(struct TreeNode* root,int* k,int* ans) {
    if(root==NULL||*k==0){
        return;
    }
    kthSmallestDfs(root->left,k,ans);
    if(*k==1){
        *ans=root->val;
    }
    (*k)--;
    kthSmallestDfs(root->right,k,ans);
    return;
}
 
int kthSmallest(struct TreeNode* root, int k) {
    int ans;
    kthSmallestDfs(root,&k,&ans);
    return ans;
}
