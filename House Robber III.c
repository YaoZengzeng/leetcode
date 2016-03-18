/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void rob2(struct TreeNode* root,int *y,int *n) {
    int y1,y2,n1,n2;
    if(root==NULL) {
        *y=*n=0;
        return;
    }
    rob2(root->left,&y1,&n1);
    rob2(root->right,&y2,&n2);
    *y=root->val+n1+n2;
    *n=(y1>n1? y1:n1) + (y2>n2? y2:n2);
    
    return;
}

int rob(struct TreeNode* root) {
    int y,n;
    rob2(root,&y,&n);
    return y>n ? y:n;
}
