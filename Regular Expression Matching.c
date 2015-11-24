bool isMatch(char* s, char* p) {
    int i;

    if(strlen(p)==0){
        if(strlen(s)==0){
            return true;
        }
    }else{
        if(p[1]!='*'){
            if(p[0]=='.'){
                if(strlen(s)>0){
                    return isMatch(s+1,p+1);
                }
            }else{
                if(p[0]==s[0]){
                    return isMatch(s+1,p+1);
                }
            }
        }else{
            if(p[0]=='.'){
                for(i=0;i<=strlen(s);i++){
                    if(isMatch(s+i,p+2)){
                        return true;
                    }
                }
            }else{
                if(isMatch(s,p+2)){
                    return true;
                }else{
                    i=0;
                    while(s[i]==p[0]){
                        if(isMatch(s+i+1,p+2)){
                            return true;
                        }
                        i++;
                    }
                    return isMatch(s+i,p+2);
                }
            }
        }
    }
    return false;    
}
