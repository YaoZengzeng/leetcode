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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> l,r,ans;
        if(root==NULL){
            return ans;
        }
        if(root->left==NULL&&root->right==NULL){
            char c[256];
            sprintf(c,"%d",root->val);
            string s=c;
            ans.push_back(s);
            return ans;
        }
        l=binaryTreePaths(root->left);
        r=binaryTreePaths(root->right);
        for(int i=0;i<l.size();i++){
            char c[256];
            sprintf(c,"%d->",root->val);
            string s=c;
            ans.push_back(s+l[i]);
        }
        for(int i=0;i<r.size();i++){
            char c[256];
            sprintf(c,"%d->",root->val);
            string s=c;
            ans.push_back(s+r[i]);
        }
        return ans;
    }
};
