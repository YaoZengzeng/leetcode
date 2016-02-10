void getPrime(int* a,int n) {
    int i,t;
    t=n;
    for(i=2;i<=n;i++){
        while(n%i==0){
            n/=i;
            a[i]++;
        }
        if(n==1){
            return;
        }
    }
}

int uniquePaths(int m, int n) {
    int i,j,C;
    int divisor[100],dividend[100];
    
    for(i=1;i<=n+m-2;i++){
        divisor[i]=dividend[i]=0;   
    }
    
    for(i=m;i<=m+n-2;i++){
        getPrime(dividend,i);
    }
    for(i=1;i<=n-1;i++){
        getPrime(divisor,i);
    }
    
    
    C=1;
    for(i=1;i<=n+m-2;i++){
        for(j=0;j<dividend[i]-divisor[i];j++){
            C*=i;
        }
    }

    return C;
}
