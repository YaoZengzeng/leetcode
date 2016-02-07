/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isValidBST2(struct TreeNode *root,int* min,bool* hasMin,int* max,bool* hasMax) {
    bool lHasMin,lHasMax,rHasMin,rHasMax;
    int lMin,lMax,rMin,rMax;    
    if(root==NULL){
        *hasMin=*hasMax=false;
        return true;
    }
    if(isValidBST2(root->left,&lMin,&lHasMin,&lMax,&lHasMax)&&isValidBST2(root->right,&rMin,&rHasMin,&rMax,&rHasMax)){
        if(lHasMax&&root->val<=lMax){
            return false;
        }
        if(rHasMin&&root->val>=rMin){
            return false;
        }
        *hasMin=true;
        if(lHasMin){
            *min=lMin;
        }else{
            *min=root->val;
        }
        *hasMax=true;
        if(rHasMax){
            *max=rMax;
        }else{
            *max=root->val;
        }
        return true;
    }
    return false;
}
 
bool isValidBST(struct TreeNode* root) {
    bool hasMin,hasMax;
    int  min,max;
    if(isValidBST2(root,&min,&hasMin,&max,&hasMax)) {
        return true;
    }else{
        return false;
    }
}
