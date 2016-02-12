void dfs(int n,int* p,int depth,int *ans) {
    int i,j,flag;
    
    if(depth==n){
        (*ans)++;
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
            dfs(n,p,depth+1,ans);
        }
    }
    return;
}

int totalNQueens(int n) {
    int p[100],ans;
    
    ans=0;
    
    dfs(n,p,0,&ans);
    
    return ans;
}
