char* getPermutation(int n, int k) {
    int num,i,j,p,times;
    int vis[10];
    char *ans;
    num=1;
    
    ans=(char*)malloc(10*sizeof(char));
    ans[n]='\0';
    
    if(n==1){
        ans[0]='1';
        return ans;
    }
    
    for(i=1;i<n;i++){
        num*=i;
        vis[i]=0;
    }
    vis[0]=0;
    
    
    for(i=0;i<n;i++){
        if(k%num==0){
            times=k/num-1;
        }else{
            times=k/num;
        }
        p=0;
        for(j=0;j<=times;j++){
            while(vis[p]==1){
                p++;
            }
            if(j!=times){
                p++;
            }
        }
        vis[p]=1;
        ans[i]=p+'1';
        if(k%num==0){
            p=n-1;
            while(p>=0){
                if(vis[p]==0){
                    ans[++i]=p+'1';
                    p--;
                }else{
                    p--;
                }
            }
            break;
        }else{
            k-=times*num;
        }
        num/=(n-1-i);
    }
    
    return ans;
}
