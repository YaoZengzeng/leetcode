int rangeBitwiseAnd(int m, int n) {
    int diff,i,mask,ans;
    diff=n-m+1;
    mask=0x40000000;
    
    ans=0;
    for(i=0;i<31;i++){
        if((m&n&mask)&&(diff<=mask)){
            ans+=mask;
        }
        mask=mask>>1;
    }
    
    return ans;
}
