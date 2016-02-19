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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<TreeNode*> s;
        vector<int> val,ans;
        TreeNode *t;
        
        if(root==NULL){
            return ans;
        }
        
        s.push_back(root);
        val.push_back(0);
        
        while(s.size()!=0){
            if(val[val.size()-1]==1){
                ans.push_back(s[s.size()-1]->val);
                val.pop_back();
                s.pop_back();
            }else{
                val[val.size()-1]=1;
                t=s[s.size()-1];
                if(t->right){
                    s.push_back(t->right);
                    val.push_back(0);
                }
                if(t->left){
                    s.push_back(t->left);
                    val.push_back(0);
                }
            }
        }
        return ans;
    }
};
