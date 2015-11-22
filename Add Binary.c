char* addBinary(char* a, char* b) {
    int i,j,k,c;
    char *p,t;
    i=strlen(a)-1;
    j=strlen(b)-1;
    k=c=0;
    
    if(i>j){
        p=(char*)malloc(i+3);
    }else{
        p=(char*)malloc(j+3);
    }
    
    while(i>=0&&j>=0){
        p[k++]=(a[i]-'0'+b[j]-'0'+c)%2+'0';
        c=(a[i]-'0'+b[j]-'0'+c)/2;
        j--,i--;
    }
    if(i>=0){
        while(i>=0){
            p[k++]=(a[i]-'0'+c)%2+'0';
            c=(a[i]-'0'+c)/2;
            i--;
        }
    }else if(j>=0){
        while(j>=0){
            p[k++]=(b[j]-'0'+c)%2+'0';
            c=(b[j]-'0'+c)/2;
            j--;
        }
    }
    
    if(c!=0){
        p[k++]=c+'0';
    }
    p[k--]='\0';
    
    for(i=0;i<=k/2;i++){
        t=p[i];
        p[i]=p[k-i];
        p[k-i]=t;
    }
    
    return p;
}
