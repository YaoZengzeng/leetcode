int ans[1000000];
int coinChange(int* coins, int coinsSize, int amount) {
    int i,j,min;
    ans[0]=0;
    for(i=1;i<=amount;i++){
        min=0x7fffffff;
        for(j=0;j<coinsSize;j++){
            if(i-coins[j]<0||ans[i-coins[j]]==-1){
                continue;
            }else{
                min= min<(1+ans[i-coins[j]]) ? min:(1+ans[i-coins[j]]);
            }
        }
        if(min==0x7fffffff){
            ans[i]=-1;
        }else{
            ans[i]=min;
        }
    }
    return ans[amount];
    
}
