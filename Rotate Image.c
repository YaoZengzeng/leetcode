void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
    int i,j,n,t,indexI,indexJ;
    
    if(matrixRowSize%2){
        indexJ=matrixRowSize/2;
    }else{
        indexJ=matrixRowSize/2-1;
    }
    indexI=matrixRowSize/2-1;
    n=matrixRowSize;
    
    for(i=0;i<=indexI;i++){
        for(j=0;j<=indexJ;j++){
            t=matrix[i][j];
            matrix[i][j]=matrix[n-1-j][i];
            matrix[n-1-j][i]=matrix[n-1-i][n-1-j];
            matrix[n-1-i][n-1-j]=matrix[j][n-1-i];
            matrix[j][n-1-i]=t;
        }
    }
}
