/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void maxPathSum2(struct TreeNode* root,int* max,int* rmax) {
    int max1,max2,rmax1,rmax2,conn;
    if(root==NULL) {
        *max=*rmax=-100000000;
        return;
    }
    
    maxPathSum2(root->left,&max1,&rmax1);
    maxPathSum2(root->right,&max2,&rmax2);
    conn=rmax1+rmax2+root->val;
    *max = root->val;
    *max = *max>max1? *max:max1;
    *max = *max>max2? *max:max2;
    *max = *max>conn? *max:conn;
    *rmax = (rmax1>rmax2? rmax1:rmax2) + root->val;
    *rmax = *rmax>root->val? *rmax:root->val;
    *max = *max>*rmax? *max:*rmax;
    
    return;
}

int maxPathSum(struct TreeNode* root) {
    int max,rmax;
    maxPathSum2(root,&max,&rmax);
    return max;
}
