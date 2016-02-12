/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    int *ans;
    int i,j,cnt,n,min;
    
    ans=(int*)malloc(matrixRowSize*matrixColSize*sizeof(int));
    cnt=0;
    
    min = matrixRowSize<matrixColSize ? matrixRowSize : matrixColSize;
    if(min%2){
        n=min/2;    
    }else{
        n=min/2-1;
    }
    
    for(i=0;i<=n;i++){
        for(j=i;j<(matrixColSize-i);j++){
            ans[cnt++]=matrix[i][j];
        }
        if(matrixRowSize%2 && min==matrixRowSize && i==n){
            return ans;
        }
        for(j=i+1;j<(matrixRowSize-i-1);j++){
            ans[cnt++]=matrix[j][matrixColSize-1-i];
        }
        for(j=i;j<(matrixColSize-i);j++){
            ans[cnt++]=matrix[matrixRowSize-1-i][matrixColSize-1-j];
        }
        if(matrixColSize%2 && min==matrixColSize && i==n){
            return ans;
        }
        for(j=i+1;j<(matrixRowSize-i-1);j++){
            ans[cnt++]=matrix[matrixRowSize-1-j][i];
        }
    }
    
    return ans;
    
}
