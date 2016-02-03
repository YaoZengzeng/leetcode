/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
int nums[100000];

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

struct TreeNode* sortedListToBST(struct ListNode* head) {
    int numsSize=0;
    struct TreeNode *root;
    
    while(head){
        nums[numsSize++]=head->val;
        head=head->next;
    }
    
    root=sortedArrayToBST(nums,numsSize);
    
    return root;
}
