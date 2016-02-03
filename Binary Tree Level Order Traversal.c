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
int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    struct TreeNode* tree[10000];
    int    level[10000],cur=0,tot=1,curLevel=0,i=0;
    int    **ans;
    if(root==NULL) {
        *returnSize=0;
        return NULL;
    }
    *columnSizes=(int*)malloc(1000*sizeof(int));
    ans=(int**)malloc(1000*sizeof(int*));
    tree[0]=root;
    level[0]=0;
    ans[0]=(int*)malloc((1<<curLevel)*sizeof(int));
    while(cur<tot) {
        if(curLevel!=level[cur]){
            curLevel=level[cur];
            if(curLevel<10){
                ans[curLevel]=(int*)malloc((1<<curLevel)*sizeof(int));
            }else{
                ans[curLevel]=(int*)malloc((1000)*sizeof(int));
            }
            (*columnSizes)[curLevel-1]=i;
            i=0;
        }
        ans[curLevel][i++]=tree[cur]->val;
        if(tree[cur]->left){
            tree[tot]=tree[cur]->left;
            level[tot++]=curLevel+1;
        }
        if(tree[cur]->right){
            tree[tot]=tree[cur]->right;
            level[tot++]=curLevel+1;
        }
        cur++;
    }
    (*columnSizes)[curLevel]=i;
    *returnSize=curLevel+1;
    return ans;
}
