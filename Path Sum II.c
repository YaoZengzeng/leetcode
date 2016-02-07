/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void dfs(int** ans,struct TreeNode* root,int sum,int** columnSizes,int* returnSize,int* path,int*pathLen) {
    int i;

    path[*pathLen]=root->val;
    (*pathLen)++;
    if(root->left==NULL&&root->right==NULL&&root->val-sum==0){
        (*columnSizes)[*returnSize]=*pathLen;
        ans[*returnSize]=(int*)malloc(*pathLen*sizeof(int));
        for(i=0;i<*pathLen;i++){
            ans[*returnSize][i]=path[i];
        }
        (*returnSize)++;
    }
    if(root->left!=NULL){
        dfs(ans,root->left,sum-root->val,columnSizes,returnSize,path,pathLen);
    }
    if(root->right!=NULL){
        dfs(ans,root->right,sum-root->val,columnSizes,returnSize,path,pathLen);
    }
    (*pathLen)--;
    return;
    
}
 
int** pathSum(struct TreeNode* root, int sum, int** columnSizes, int* returnSize) {
    int **ans,i,path[1000],pathLen;
    
    *returnSize=0;
    if(root==NULL){
        return NULL;
    }
    
    (*columnSizes)=(int*)malloc(1000*sizeof(int));
    ans=(int**)malloc(1000*sizeof(int*));
    pathLen=0;
    
    dfs(ans,root,sum,columnSizes,returnSize,path,&pathLen);
    
    if(*returnSize==0) {
        return NULL;
    }
    return ans;
}
