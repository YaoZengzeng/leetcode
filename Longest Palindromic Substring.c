char* longestPalindrome(char* s) {
    int t,i,j,len,max;
    char* p;
    
    max=0;
    for(t=0;t<strlen(s);t++){
        len=0;
        i=j=t;
        while(i>=0&&j<strlen(s)&&s[i]==s[j]){
            i--,j++,len++;
        }
        if(len*2-1>max){
            max=len*2-1;
            p=s+1+i;
        }
        
        len=0;
        i=t,j=t+1;
        while(i>=0&&j<strlen(s)&&s[i]==s[j]){
            i--,j++,len++;
        }
        if(len*2>max){
            max=len*2;
            p=s+i+1;
        }
    }
    
    *(p+max)='\0';
    return p;
}
