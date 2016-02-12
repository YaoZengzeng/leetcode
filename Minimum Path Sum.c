int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int i,j,min;
    for(i=0;i<gridRowSize;i++){
        for(j=0;j<gridColSize;j++){
            if(i==0&&j==0){
                continue;
            }else if(j==0){
                grid[i][j]+=grid[i-1][j];
            }else if(i==0){
                grid[i][j]+=grid[i][j-1];
            }else{
                min=grid[i][j-1]<grid[i-1][j] ? grid[i][j-1] : grid[i-1][j];
                grid[i][j]+=min;
            }
        }
    }
    
    return grid[gridRowSize-1][gridColSize-1];
}
