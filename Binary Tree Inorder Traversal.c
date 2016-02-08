/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    struct TreeNode *stack[1000];
    int top=0,*ans;
    
    ans=(int*)malloc(1000*sizeof(int));
    
    if(root==NULL){
        *returnSize==0;
        return NULL;
    }
    
    *returnSize=0;
    stack[top++]=root;
    while(top>0){
        while(stack[top-1]->left!=NULL){
            stack[top]=stack[top-1]->left;
            stack[top-1]->left=NULL;		//tricky
            top++;
        }
        if(stack[top-1]->right!=NULL){
            ans[(*returnSize)++]=stack[top-1]->val;
             stack[top-1]=stack[top-1]->right;
        }else{
            ans[(*returnSize)++]=stack[top-1]->val;
            top--;
        }
    }
    
    return ans;
}
