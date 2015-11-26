/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
void dfs(int left,int right,int remaining,char* val,char **ans,int *returnSize) {
    if(remaining==0&&left==right){
        ans[*returnSize]=(char*)malloc(2*left+2);
        strcpy(ans[*returnSize],val);
        (*returnSize)++;
        return;
    }
    
    if(remaining>0){
        val[left+right]='(';
        dfs(left+1,right,remaining-1,val,ans,returnSize);
    }
    
    if(left>right){
        val[left+right]=')';
        dfs(left,right+1,remaining,val,ans,returnSize);
    }
    
    return;
}
 
 
 
char** generateParenthesis(int n, int* returnSize) {
    char** ans=(char**)malloc(sizeof(char*)*10000);
    char val[2*n+1];
    val[2*n]='\0';
    *returnSize=0;
    
    dfs(0,0,n,val,ans,returnSize);
    
    return ans;
}
