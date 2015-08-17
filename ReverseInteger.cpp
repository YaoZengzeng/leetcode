int reverse(int x) {
    long long X,Y,t;
    int y;
    
    X=x;  
    
    if(X==0){
        return 0;
    }else{
        Y=y=0;
        while(X){
            t=X%10;
            Y=Y*10+t;
            y=y*10+t;
            X/=10;
        }
    }
    
    if(y!=Y){
      return 0;  
    } 
    
    return Y;
    
}
