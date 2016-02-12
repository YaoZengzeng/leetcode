int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    int a[1000];
    int i,j;
    for(i=0;i<obstacleGridColSize;i++){
        a[i]=0;
    }
    
    if(obstacleGrid[0][0]==1){
        return 0;
    }else{
        a[0]=1;
    }
    for(i=0;i<obstacleGridRowSize;i++){
        for(j=0;j<obstacleGridColSize;j++){
            if(j!=0){
                a[j]=a[j-1]+a[j];
            }
            if(obstacleGrid[i][j]==1){
                a[j]=0;
            }
        }
    }
    
    return a[obstacleGridColSize-1];
}
