/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize) {
    long long num=1<<n,cnt=0;
    long long i,j,now;
    int *vis=(int*)malloc(sizeof(int)*num);
    int *ans=(int*)malloc(sizeof(int)*num);
    
    if(n==0){
        *returnSize=1;
        ans[0]=0;
        return ans;
    }
    
    memset(vis,0,sizeof(int)*num);
    
    vis[0]=1;
    ans[0]=now=0;
    for(i=1;i<=num;i++){
        for(j=0;j<n;j++){
            if(vis[now^(1<<j)]==0){
                now=now^(1<<j);
                vis[now]=1;
                ans[i]=now;
                break;
            }
        }
    }
    
    *returnSize=num;
    return ans;
    
}
