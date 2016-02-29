char nums[10000000];
int countPrimes(int n) {
    int i,cnt,t;
    if(n<2){
        return 0;
    }
    
    for(i=0;i<n;i++){
        nums[i]=0;
    }
    
    cnt=0;
    for(i=2;i<n;i++){
        if(nums[i]==0){
            cnt++;
        }
        t=2*i;
        while(t<n){
            nums[t]=1;
            t+=i;
        }
    }
    
    return cnt;
    
    
}
