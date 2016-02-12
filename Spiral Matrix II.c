/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n) {
    int i,j,**ans,cnt,index;
    
    ans=(int**)malloc(n*sizeof(int*));
    
    for(i=0;i<n;i++){
        ans[i]=(int*)malloc(n*sizeof(int));
    }
    
    if(n%2){
        index=n/2;
    }else{
        index=n/2-1;
    }
    
    cnt=1;
    for(i=0;i<=index;i++){
        for(j=i;j<(n-i);j++){
            ans[i][j]=cnt++;
        }
        if(n%2&& i==index){
            return ans;
        }
        for(j=i+1;j<(n-i-1);j++){
            ans[j][n-1-i]=cnt++;
        }
        for(j=i;j<(n-i);j++){
            ans[n-1-i][n-1-j]=cnt++;
        }
        for(j=i+1;j<(n-i-1);j++){
            ans[n-1-j][i]=cnt++;
        }
    }
    
    return ans;
}
