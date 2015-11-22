int mySqrt(int x) {
    long long i=1,j;
    long long t=x;
    if(x==0){
        return 0;
    }
    while(i*i*4<t){
        i*=2;
    }
    for(j=i;j<=i*2;j++){
        if(j*j<=t&&(j+1)*(j+1)>t){
            return j;
        }
    }
}
