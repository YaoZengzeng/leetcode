/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    struct TreeNode *root;
    
    if(numsSize==0){
        return NULL;
    }
    
    root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val=nums[numsSize/2];
    
    root->left=sortedArrayToBST(nums,numsSize/2);
    root->right=sortedArrayToBST(nums+numsSize/2+1,numsSize-numsSize/2-1);
    
    return root;
}
