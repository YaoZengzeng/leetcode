int strStr(char* haystack, char* needle) {
    int next[strlen(needle)];
    int i,j,t;
    
    if(strlen(haystack)<strlen(needle)){
        return -1;
    }
    if(strlen(needle)==0){
        return 0;
    }
    
    next[0]=0;
    for(i=1;i<strlen(needle);i++){
        next[i]=0;
        t=i-1;
        while(t){
            t=next[t];
            if(needle[t]==needle[i-1]&&t!=i-1){
                next[i]=t+1;
                break;
            }
        }
    }
    
    j=0;
    for(i=0;i<strlen(haystack);i++){
        if(haystack[i]==needle[j]){
            j++;
            if(j>=strlen(needle)){
                return i-j+1;
            }
        }else{
            while(j){
                j=next[j];
                if(haystack[i]==needle[j]){
                    j++;
                    break;
                }
            }
        }
    }
    
    return -1;
}
