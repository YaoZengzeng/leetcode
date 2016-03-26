bool isMatch(char* s, char* p) {
    int indexS=0,indexP=0;
    int preS,preP;
    bool star=false;
    
    while(indexS<strlen(s)) {
        if(p[indexP]=='?') {
            indexS++,indexP++;
        } else if(p[indexP]==s[indexS]){
            indexS++,indexP++;
        } else if(p[indexP]=='*') {
            star=true;
            while(p[indexP]=='*') {
                indexP++;
            }
            if(indexP==strlen(p)) {
                return true;
            }
            preS=indexS;
            preP=indexP;
        } else {
            if(star==false) {
                return false;
            }
            preS++;
            indexS=preS;
            indexP=preP;
        }
    }
    while(p[indexP]=='*') {
        indexP++;
    }
    if(indexP==strlen(p)) {
        return true;
    } else {
        return false;
    }
    
}
