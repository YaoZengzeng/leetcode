/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
void dfs(int n,char **chess,int *p,int depth,int *returnSize,char ***ans) {

    int i,j,flag;

    if(depth==n){

        ans[*returnSize]=(char**)malloc(n*sizeof(char*));

        for(i=0;i<n;i++){
            ans[*returnSize][i]=(char*)malloc((n+1)*sizeof(char));
            for(j=0;j<n;j++){
                ans[*returnSize][i][j]=chess[i][j];
            }
            ans[*returnSize][i][n]='\0';
        }
        (*returnSize)++;
        return;
    }

    for(i=0;i<n;i++){
        flag=1;
        for(j=0;j<depth;j++){
            if(abs(depth-j)==abs(p[j]-i)||p[j]==i){
                flag=0;
                break;
            }
        }

        if(flag){
            p[depth]=i;
            chess[depth][i]='Q';
            dfs(n,chess,p,depth+1,returnSize,ans);
            chess[depth][i]='.';
        }
    }
}





char*** solveNQueens(int n, int* returnSize) {

    char ***ans,**chess;
    int p[1000];
    int i,j;

    
    ans=(char***)malloc(1000*sizeof(char**));
    chess=(char**)malloc((n+1)*sizeof(char*));

    for(i=0;i<n;i++){
        chess[i]=(char*)malloc(n*sizeof(char));
        for(j=0;j<n;j++){
            chess[i][j]='.';
        }
        chess[i][n]='\0';
    }

    *returnSize=0;

    dfs(n,chess,p,0,returnSize,ans);

    return ans;

}
