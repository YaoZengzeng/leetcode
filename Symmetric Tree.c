/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
void traverse(struct TreeNode *root,char *record,int *len,int order) {
    if(root==NULL) {
        record[(*len)++]='#';
        return;
    }
    record[(*len)++]=root->val;
    if(order==0) {
        traverse(root->left,record,len,order);
        traverse(root->right,record,len,order);
    }else {
        traverse(root->right,record,len,order);
        traverse(root->left,record,len,order);
    }
}
 
char    left[100000],right[100000];
int     leftNum,rightNum;
bool isSymmetric(struct TreeNode* root) {
        if(root==NULL) {
            return true;
        }else if(root->left==NULL && root->right!=NULL) {
            return false;
        }else if(root->left!=NULL && root->right==NULL) {
            return false;
        }else {
            leftNum=rightNum=0;
            traverse(root->left,left,&leftNum,0);
            traverse(root->right,right,&rightNum,1);
            if(leftNum!=rightNum) {
                return false;
            }else {
                for(int i=0;i<leftNum;i++) {
                    if(left[i]!=right[i]) {
                        return false;
                    }
                }
                return true;
            }
        }
}
