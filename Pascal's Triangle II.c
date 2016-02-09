/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    int *p[2],i,j;
    
    
    p[0]=(int*)malloc((rowIndex+1)*sizeof(int));
    p[1]=(int*)malloc((rowIndex+1)*sizeof(int));
    
    *returnSize=rowIndex+1;
    if(rowIndex==0){
        p[0][0]=1;
        return p[0];
    }else if(rowIndex==1){
        p[0][0]=p[0][1]=1;
        return p[0];
    }
    p[0][0]=p[0][1]=1;
    
    for(i=2;i<=rowIndex;i++){
        p[(i+1)%2][0]=p[(i+1)%2][i]=1;
        for(j=1;j<i;j++){
            p[(i+1)%2][j]=p[i%2][j-1]+p[i%2][j];
        }
    }
    return p[(rowIndex+1)%2];
}
