int cnt[1000][1000];

int dfs(int** matrix,int matrixRowSize,int matrixColSize,int i,int j){
    int max=0,t;
    if(cnt[i][j]!=1){
        return cnt[i][j];
    }
    if(i>0&&matrix[i-1][j]>matrix[i][j]){
        t=dfs(matrix,matrixRowSize,matrixColSize,i-1,j);
        max= t>max ? t:max;
    }
    if(i<matrixRowSize-1&&matrix[i+1][j]>matrix[i][j]){
        t=dfs(matrix,matrixRowSize,matrixColSize,i+1,j);
        max= t>max ? t:max;
    }
    if(j>0&&matrix[i][j-1]>matrix[i][j]){
        t=dfs(matrix,matrixRowSize,matrixColSize,i,j-1);
        max= t>max ? t:max;
    }
    if(j<matrixColSize-1&&matrix[i][j+1]>matrix[i][j]){
        t=dfs(matrix,matrixRowSize,matrixColSize,i,j+1);
        max= t>max ? t:max;
    }
    cnt[i][j]=max+1;
    return cnt[i][j];
}

int longestIncreasingPath(int** matrix, int matrixRowSize, int matrixColSize) {
    int i,j,temp;
    int max=1;
    if(matrixRowSize==0&&matrixColSize==0){
        return 0;
    }
    for(i=0;i<matrixRowSize;i++){
        for(j=0;j<matrixColSize;j++){
            cnt[i][j]=1;
        }
    }
    for(i=0;i<matrixRowSize;i++){
        for(j=0;j<matrixColSize;j++){
            temp=dfs(matrix,matrixRowSize,matrixColSize,i,j);
            max= temp>max ? temp:max;
        }
    }
    
    return max;
}
