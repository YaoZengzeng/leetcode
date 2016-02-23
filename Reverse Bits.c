uint32_t reverseBits(uint32_t n) {
    int b[32],i;
    
    for(i=0;i<32;i++){
        b[i]=n%2;
        n/=2;
    }
    
    n=0;
    for(i=0;i<32;i++){
        n=n*2+b[i];
    }
    
    return n;
}
