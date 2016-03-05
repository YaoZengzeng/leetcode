int countDigitOne(int n) {
    int ans=0,t=n;
    int times=1;
    if(n<=0){
        return 0;
    }
    while(t){
        ans+=(t/10)*times;
        if(t%10==1){
            ans+=n%times+1;
        }else if(t%10>1){
            ans+=times;
        }
        t/=10;
        times*=10;
    }
    return ans;
}

