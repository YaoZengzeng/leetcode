int vis[1000][1000];

void dfs(int i,int j,int gridRowSize,int gridColSize,char** grid){
    if(i<0||i>=gridRowSize||j<0||j>=gridColSize||grid[i][j]=='0'||vis[i][j]==1){
        return;
    }
    vis[i][j]=1;
    dfs(i,j-1,gridRowSize,gridColSize,grid);
    dfs(i,j+1,gridRowSize,gridColSize,grid);
    dfs(i-1,j,gridRowSize,gridColSize,grid);
    dfs(i+1,j,gridRowSize,gridColSize,grid);
    
    return;
}
int numIslands(char** grid, int gridRowSize, int gridColSize) {
    int i,j,ans;
    
    for(i=0;i<gridRowSize;i++){
        for(j=0;j<gridColSize;j++){
            vis[i][j]=0;
        }
    }
    
    ans=0;
    for(i=0;i<gridRowSize;i++){
        for(j=0;j<gridColSize;j++){
            if(!vis[i][j]&&grid[i][j]=='1'){
                ans++;
                dfs(i,j,gridRowSize,gridColSize,grid);
            }
        }
    }
    
    return ans;
}
