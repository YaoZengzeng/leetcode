void reverseWords(char *s) {
    int i,beg,end,cnt,state,p,len;
    char c;
    
    while(strlen(s)>0&&s[strlen(s)-1]==' '){
        s[strlen(s)-1]='\0';
    }
    
    len=strlen(s);
    
    for(i=0;i<strlen(s)/2;i++){
        c=s[i];
        s[i]=s[strlen(s)-1-i];
        s[strlen(s)-1-i]=c;
    }
    
    beg=-1;
    for(end=0;end<=strlen(s);end++){
        if(s[end]==' '||end==strlen(s)){
            for(i=0;i<(end-beg-1)/2;i++){
                c=s[beg+i+1];
                s[beg+i+1]=s[end-1-i];
                s[end-1-i]=c;
            }
            beg=end;
        }
    }
    
    state=p=0;
    for(i=0;i<strlen(s);i++){
        if(s[i]!=' '){
            s[p++]=s[i];
            state=0;
        }else{
            if(state==0){
                s[p++]=s[i];
                state=1;
            }
        }
    }
    s[p]='\0';
    while(strlen(s)>0&&s[strlen(s)-1]==' '){
        s[strlen(s)-1]='\0';
    }

    return;
    
}
