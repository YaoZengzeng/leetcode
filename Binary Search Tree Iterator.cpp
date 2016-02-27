/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    vector<struct TreeNode*> s;
    
public:
    BSTIterator(TreeNode *root) {
        TreeNode *p=root;
        while(p){
            s.push_back(p);
            p=p->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return s.size()!=0;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *p;
        int val;
        val=s[s.size()-1]->val;
        p=s[s.size()-1]->right;
        s.pop_back();
        while(p){
            s.push_back(p);
            p=p->left;
        }
        return val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
