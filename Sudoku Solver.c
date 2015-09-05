void solveSudoku(char** board, int boardRowSize, int boardColSize) {
    static int vis1[9][9],vis2[9][9],vis3[9][9];
    static int i=0,j=0,success=0;
    int k,m,n;
    
    if(i==0&&j==0){
        success=0;
        for(k=0;k<9;k++){
            memset(vis1[k],0,sizeof(vis1[k]));
            memset(vis2[k],0,sizeof(vis2[k]));
            memset(vis3[k],0,sizeof(vis3[k]));
        }
        
        for(m=0;m<9;m++){
            for(n=0;n<9;n++){
                if(board[m][n]!='.'){
                    vis1[m][board[m][n]-'1']=1;
                    vis2[n][board[m][n]-'1']=1;
                    vis3[m/3*3+n/3][board[m][n]-'1']=1;
                }
            }
        }
    }
    
    if(i==9){
        success=1;
        i=j=0;
        return;
    }
    
    if(board[i][j]!='.'){
        if(j==8){
            i++,j=0;
        }else{
            j++;
        }
        solveSudoku(board,boardRowSize,boardColSize);
        return;
    }
    
    for(k=0;k<9;k++){
        if(!vis1[i][k]&&!vis2[j][k]&&!vis3[i/3*3+j/3][k]){
            board[i][j]=k+'1';
            vis1[i][k]=vis2[j][k]=vis3[i/3*3+j/3][k]=1;
            m=i,n=j;
            if(j==8){
                i++,j=0;
            }else{
                j++;
            }
            solveSudoku(board,boardRowSize,boardColSize);
            if(success){
                return;
            }
            i=m,j=n;
            vis1[i][k]=vis2[j][k]=vis3[i/3*3+j/3][k]=0;
            board[i][j]='.';
        }
    }
    
    return;
}
