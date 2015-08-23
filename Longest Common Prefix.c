char* longestCommonPrefix(char** strs, int strsSize) {
    int i,pos,max;
    char c,*p;
    
    max=0;
    for(i=0;i<strsSize;i++){
        if(strlen(strs[i])>max){
            max=strlen(strs[i]);
        }
    }
    max+=1;
    p=(char*)malloc(max);
    
    if(strsSize<=0){
        *p='\0';
        return p;
    }
    
    pos=0;
    while(1){
        c=strs[0][pos];
        for(i=1;i<strsSize;i++){
            if(c!=strs[i][pos]){
                p[pos]='\0';
                return p;
            }
        }
        *(p+pos)=strs[0][pos];
        pos++;
        if(pos>=strlen(strs[0])){
            break;
        }
    }
    p[pos]='\0';
    return strs[0];
}
