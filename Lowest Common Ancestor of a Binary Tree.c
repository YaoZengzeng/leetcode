/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
struct TreeNode* lowestCommonAncestor2(struct TreeNode* root,struct TreeNode* p,bool* hasP,struct TreeNode* q,bool* hasQ) {
    bool hasP1,hasQ1,hasP2,hasQ2;
    struct TreeNode *ret1, *ret2;
    if(root==NULL){
        return NULL;
    }
    
    hasP1=hasP2=hasQ1=hasQ2=false;
    ret1=lowestCommonAncestor2(root->left,p,&hasP1,q,&hasQ1);
    if(hasP1&&hasQ1){
        *hasP=*hasQ=true;
        return ret1;
    }
    ret2=lowestCommonAncestor2(root->right,p,&hasP2,q,&hasQ2);
    if(hasP2&&hasQ2){
        *hasP=*hasQ=true;
        return ret2;
    }
    if(root==p||hasP1||hasP2){
        *hasP=true;
    }
    if(root==q||hasQ1||hasQ2){
        *hasQ=true;
    }
    if(*hasP&&*hasQ){
        return root;
    }else{
        return NULL;
    }
}
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    bool hasP=false,hasQ=false;
    return lowestCommonAncestor2(root,p,&hasP,q,&hasQ);
}
