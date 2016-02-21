int titleToNumber(char* s) {
    int i,ans;
    ans=0;
    for(i=0; i<strlen(s); i++){
        ans = ans*26 + s[i]-'A'+1;
    }
    
    return ans;
}
