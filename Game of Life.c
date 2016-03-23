int countLive(int** board,int boardRowSize,int boardColSize,int i,int j) {
    int a,b,cnt=0;
    for(a=i-1;a<=i+1;a++) {
        for(b=j-1;b<=j+1;b++) {
            if(a==i&&b==j) {
                continue;
            }
            if(a>=0&&a<boardRowSize&&b>=0&&b<boardColSize&&board[a][b]%10) {
                cnt++;
            }
        }
    }
    return cnt;
}

void gameOfLife(int** board, int boardRowSize, int boardColSize) {
    int live,i,j;
    
    for(i=0;i<boardRowSize;i++) {
        for(j=0;j<boardColSize;j++) {
            live=countLive(board,boardRowSize,boardColSize,i,j);
            if(board[i][j]==0) {
                if(live==3) {
                    board[i][j]+=10;
                }
            } else {
                if(live==2||live==3) {
                    board[i][j]+=10;
                }
            }
        }
    }
    
    for(i=0;i<boardRowSize;i++) {
        for(j=0;j<boardColSize;j++) {
            board[i][j]/=10;
        }
    }
    
    return;
}
