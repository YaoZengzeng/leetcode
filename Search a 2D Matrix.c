bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int l,mid,r;
    int row,col;
    l=0,r=matrixRowSize*matrixColSize-1;
    
    while(l<=r){
        mid=(l+r)/2;
        row=mid/matrixColSize;
        col=mid-row*matrixColSize;
        if(matrix[row][col]==target){
            return true;
        }else if(matrix[row][col]>target){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return false;
}
