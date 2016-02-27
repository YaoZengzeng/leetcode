/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void traverse(struct TreeNode* node,int depth,vector<int>& ans){
        if(node==NULL){
            return;
        }
        if(ans.size()<depth){
            ans.push_back(node->val);
        }
        traverse(node->right,depth+1,ans);
        traverse(node->left,depth+1,ans);
        
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        traverse(root,1,ans);
        
        return ans;
    }
};
