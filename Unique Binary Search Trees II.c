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
 

struct TreeNode** generateTrees2(int n,int l,int* returnSize) {

    struct TreeNode **lAns,**rAns,**ans;
    int lReturnSize,rReturnSize;
    int i,j,cnt,a,b;

    

    if(n==0){
        *returnSize=1;
        ans=(struct TreeNode**)malloc(sizeof(struct TreeNode*));
        ans[0]=NULL;
        return ans;

    }

    
    ans=(struct TreeNode**)malloc(10000*sizeof(struct TreeNode*));
    cnt=0;
    for(i=l;i<l+n;i++){
        lAns=generateTrees2(i-l,l,&lReturnSize);
        rAns=generateTrees2(l+n-i-1,i+1,&rReturnSize);
        for(a=0;a<lReturnSize;a++){
            for(b=0;b<rReturnSize;b++){
                ans[cnt]=(struct TreeNode*)malloc(sizeof(struct TreeNode));
                ans[cnt]->val=i;
                ans[cnt]->left=lAns[a];
                ans[cnt]->right=rAns[b];
                cnt++;
            }
        }
    }

    *returnSize=cnt;
    return ans;

}

 

struct TreeNode** generateTrees(int n, int* returnSize) {
    if(n==0){
        *returnSize=0;
        return NULL;
    }
    return generateTrees2(n,1,returnSize);

}
