double myPow2(double x,int n) {
    if(x<0.5 && x>-0.5 && n>200){
        return 0.0;
    }
    if(n==1){
        return x;
    }
    if(n%2){
        return x*myPow2(x,n/2)*myPow2(x,n/2);
    }else{
        return myPow2(x,n/2)*myPow2(x,n/2);
    }    
}


double myPow(double x, int n) {
    if(n==0){
        return 1.0;
    }
    if(x==1.0){
        return 1.0;
    }else if(x==-1.0){
        if(n%2){
            return -1.0;
        }else{
            return 1.0;
        }
    }
    if(n<0){
        return myPow2(1/x,-n);
    }else{
        return myPow2(x,n);
    }
}

