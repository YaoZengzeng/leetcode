bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
    static int **vis,x,y,pos=0;
    int i,j,x1,y1,x2,y2,tpos;
    if(pos==0){
    
        vis=(int**)malloc(boardRowSize*sizeof(int*));
        for(i=0;i<boardRowSize;i++){
            vis[i]=(int*)malloc(boardColSize*sizeof(int));
            memset(vis[i],0,boardColSize*sizeof(int));
        }
		
        for(i=0;i<boardRowSize;i++){
            for(j=0;j<boardColSize;j++){
                if(board[i][j]==word[0]){
                    pos++;
                    vis[i][j]=1;
                    x=i,y=j;
                    if(exist(board,boardRowSize,boardColSize,word)){
                    	pos=0;
               	        for(j=0;j<boardRowSize;j++){
				            free(vis[j]);
        				}
        				free(vis);
                        return true;
                    }
                    vis[i][j]=0;
                    pos=0;
                }
            }
        }
        
        for(i=0;i<boardRowSize;i++){
            free(vis[i]);
        }
        free(vis);
        return false;
    }else{
        if(pos==strlen(word)){
            return true;
        }
        tpos=pos;
        
        x1=x,y1=y;
        if(x1==boardRowSize-1){
            goto L1;
        }else{
            x=x1+1;
        }
        if(!vis[x][y]&&board[x][y]==word[pos]){
            vis[x][y]=1;
            x2=x,y2=y;
            pos++;
            if(exist(board,boardRowSize,boardColSize,word)){
                return true;
            }
            vis[x2][y2]=0;
        }
        pos=tpos;
        
L1:     if(x1==0){
            goto L2;
        }else{
            x=x1-1;
        }
        y=y1;
        if(!vis[x][y]&&board[x][y]==word[pos]){
            vis[x][y]=1;
            x2=x,y2=y;
            pos++;
            if(exist(board,boardRowSize,boardColSize,word)){
                return true;
            }
            vis[x2][y2]=0;
        }
        pos=tpos;
        
L2:     if(y1==boardColSize-1){
            goto L3;
        }else{
            y=y1+1;
        }
        x=x1;
        if(!vis[x][y]&&board[x][y]==word[pos]){
            vis[x][y]=1;
            x2=x,y2=y;
            pos++;
            if(exist(board,boardRowSize,boardColSize,word)){
                return true;
            }
            vis[x2][y2]=0;
        }
        pos=tpos;
        
L3:     if(y1==0){
            goto L4;
        }else{
            y=y1-1;
        }
        x=x1;
        if(!vis[x][y]&&board[x][y]==word[pos]){
            vis[x][y]=1;
            x2=x,y2=y;
            pos++;
            if(exist(board,boardRowSize,boardColSize,word)){
                return true;
            }
            vis[x2][y2]=0;
        }
L4:     return false;
    }
    
}
