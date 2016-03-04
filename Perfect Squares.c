int ans[100000];

int numSquares(int n) {
    int i,min,j;
    ans[0]=0;
    ans[1]=1;
    for(i=2;i<=n;i++){
        min=0x7fffffff;
        for(j=1;j*j<=i;j++){
            if(1+ans[i-j*j]<min){
                min=1+ans[i-j*j];
            }
        }
        ans[i]=min;
    }
    return ans[n];
}
