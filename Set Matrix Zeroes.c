void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    int i,j,a,b;
    int row[1000],rowNum,col[1000],colNum;
    
    rowNum=colNum=0;
    for(i=0;i<matrixRowSize;i++){
        for(j=0;j<matrixColSize;j++){
            if(matrix[i][j]==0){
                row[rowNum++]=i;
                col[colNum++]=j;
            }
        }
    }
    for(i=0;i<rowNum;i++){
        for(j=0;j<matrixColSize;j++){
            matrix[row[i]][j]=0;
        }
    }
    for(i=0;i<colNum;i++){
        for(j=0;j<matrixRowSize;j++){
            matrix[j][col[i]]=0;
        }
    }
    return ;
}
