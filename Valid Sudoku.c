bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    int vis1[9][9],vis2[9][9],vis3[9][9],i,j,k;
    
    for(i=0;i<9;i++){
        memset(vis1[i],0,sizeof(vis1[i]));
        memset(vis2[i],0,sizeof(vis2[i]));
        memset(vis3[i],0,sizeof(vis3[i]));
    }
    
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(board[i][j]!='.'){
            if(vis1[i][board[i][j]-'1']){
                return false;
            }else{
                vis1[i][board[i][j]-'1']=1;
            }
            if(vis2[j][board[i][j]-'1']){
                return false;
            }else{
                vis2[j][board[i][j]-'1']=1;
            }
            if(vis3[i/3*3+j/3][board[i][j]-'1']){
                return false;
            }else{
                vis3[i/3*3+j/3][board[i][j]-'1']=1;
            }
            }
        }
    }
    
    
    return true;
}
