int compareVersion(char* version1, char* version2) {
    char *p1,*p2;
    int v1,v2;
    if(strcmp(version1,version2)==0){
        return 0;
    }
    
    p1=version1,p2=version2;
    while(*p1&&*p2){
        v1=0;v2=0;
        while(*p1!='.'&&*p1!='\0'){
            v1=v1*10+*p1-'0';
            p1++;
        }
        if(*p1=='.'){
            p1++;
        }
        while(*p2!='.'&&*p2!='\0'){
            v2=v2*10+*p2-'0';
            p2++;
        }
        if(*p2=='.'){
            p2++;
        }
        if(v1>v2){
            return 1;
        }else if(v2>v1){
            return -1;
        }
    }
    
    if(*p1=='\0' && *p2=='\0'){
        return 0;
    }else if(*p1=='\0'){
        while(*p2=='.'||*p2=='0'){
            p2++;
        }
        if(*p2=='\0'){
            return 0;
        }else{
            return -1;
        }
    }else{
        while(*p1=='.'||*p1=='0'){
            p1++;
        }
        if(*p1=='\0'){
            return 0;
        }else{
            return 1;
        }
    }

}
