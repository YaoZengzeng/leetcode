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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<TreeNode*> s;
        vector<int> ans;
        TreeNode* t;
        
        if(root==NULL){
            return ans;
        }
        
        s.push_back(root);
        
        while(s.size()!=0){
            ans.push_back(s[s.size()-1]->val);
            t=s[s.size()-1];
            s.pop_back();
            if(t->right){
                s.push_back(t->right);
            }
            if(t->left){
                s.push_back(t->left);
            }
        }
        
        return ans;
    }
};
