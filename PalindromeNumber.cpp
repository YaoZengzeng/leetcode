bool isPalindrome(int x) {
    long long X=x,Y=0;
    
    if(X<0){
        return false;
    }
    
    while(X){
     Y=Y*10+X%10;
     X/=10;
    }
    
    return X==Y;
}
