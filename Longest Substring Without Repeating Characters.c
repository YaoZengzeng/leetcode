int lengthOfLongestSubstring(char* s) {
    int i,max,start;
    int pos[128];
    memset(pos,0,128*sizeof(int));
    
    if(strlen(s)==0){
        return 0;
    }
    
    max=start=1;
    for(i=1;i<=strlen(s);i++){
        if(pos[s[i-1]]>=start){
            start=pos[s[i-1]]+1;
            pos[s[i-1]]=i;
        }else{
            pos[s[i-1]]=i;
            max=i-start+1>max?i-start+1:max;
        }
    }
    
    return max;
}
