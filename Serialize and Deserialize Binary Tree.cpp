/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        if(root==NULL){
            return ans+"NULL";
        }
        char s[20];
        sprintf(s,"%d",root->val);
        ans+=s;
        ans+=(","+serialize(root->left)+","+serialize(root->right));
        return ans;
    }

    TreeNode* deserialize2(string& data,int *pos) {
        if(data[*pos]=='N'){
            *pos+=4;
            return NULL;
        }
        TreeNode* root=(TreeNode*)malloc(sizeof(TreeNode));
        int val=0;
        int flag=0;
        while(data[*pos]!=','){
            if(data[*pos]=='-'){
                flag=1;
            }else{
                val=val*10+data[*pos]-'0';
            }
            (*pos)++;
        }
        if(flag){
            val=-val;
        }
        root->val=val;
        (*pos)++;
        root->left=deserialize2(data,pos);
        (*pos)++;
        root->right=deserialize2(data,pos);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos=0;
        return deserialize2(data,&pos);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
