/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
void sumNumbers2(struct TreeNode* root,int val,int *sum) {
    
    val=val*10+root->val;
    if(root->left==NULL && root->right==NULL){
        *sum+=val;
        return;
    }
    if(root->left){
        sumNumbers2(root->left,val,sum);
    }
    if(root->right){
        sumNumbers2(root->right,val,sum);
    }
    
    return;
}

int sumNumbers(struct TreeNode* root) {
    int sum=0;
    
    if(root==NULL){
        return 0;
    }
    sumNumbers2(root,0,&sum);
    return sum;
}
