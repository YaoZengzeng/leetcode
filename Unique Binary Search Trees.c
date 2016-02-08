int numTrees(int n) {
    int ans[10000],i,j;
    ans[0]=1;
    for(i=1;i<=n;i++){
        ans[i]=0;
        for(j=0;j<i;j++){
            ans[i]+=ans[j]*ans[i-1-j];
        }
    }
    return ans[n];
}
