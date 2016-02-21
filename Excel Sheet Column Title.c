char* convertToTitle(int n) {
    char* ans = (char*) malloc(1000*sizeof(char));
    char t;
    int len,i;
    
    len=0;
    while(n){
        if(n%26 == 0){
            ans[len++] = 'Z';
            n-=26;
        }else{
            ans[len++] = n%26-1+'A';
        }
        n=n/26;
    }
    
    ans[len]='\0';
    for(i=0;i<len/2;i++){
        t = ans[i];
        ans[i] = ans[len-i-1];
        ans[len-i-1] = t;
    }
    
    return ans;
}
