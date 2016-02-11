int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes) {
    int min[2][10000],i,j,t;
    
    for(i=0;i<triangleColSizes[triangleRowSize-1];i++){
        min[1][i]=triangle[triangleRowSize-1][i];
    }
    
    for(i=triangleRowSize-2;i>=0;i--){
        for(j=0;j<=i;j++){
            t=min[1][j]<min[1][j+1]?min[1][j]:min[1][j+1];
            
            min[0][j]=t+triangle[i][j];
        }
        for(j=0;j<=i;j++){
            min[1][j]=min[0][j];
        }
    }
    return min[1][0];
}
