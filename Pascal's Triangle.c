/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes, int* returnSize) {
    int i,j,**ans;
    
    if(numRows<1){
        *returnSize=0;
        return NULL;
    }
    
    *returnSize=numRows;
    (*columnSizes)=(int*)malloc(numRows*sizeof(int));
    ans=(int**)malloc(numRows*sizeof(int*));
    
    for(i=0;i<numRows;i++){
        (*columnSizes)[i]=i+1;
    }
    
    ans[0]=(int*)malloc(sizeof(int));
    ans[0][0]=1;
    for(i=1;i<numRows;i++){
        ans[i]=(int*)malloc((i+1)*sizeof(int));
        ans[i][0]=ans[i][i]=1;
        for(j=1;j<i;j++){
            ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
        }
    }
    return ans;
}
