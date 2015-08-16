int myAtoi(char* str) {
    long long t=0,f=0;
    char *p=str;
    int len=0;
    
    while(*p==' '){
        p++;
    }
    
    if(*p=='+'){
        p++;
    } else if(*p=='-'){
        p++;
        f=1;
    }
    
    if(!(*p>='0'&&*p<='9')){
        return 0;
    }
    
    while(*p=='0') p++;
    
    while(*p){
        if(!(*p>='0'&&*p<='9')){
            goto L;
        }
        t=t*10+(*p-'0');
        p++;
        if(++len>11) break;
    }
    
L:
    t=f?-t:t;

    if(t>INT_MAX){
        return INT_MAX;
    }else if(t<INT_MIN){
        return INT_MIN;
    }
    return t;
}
