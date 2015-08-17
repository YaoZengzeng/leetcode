int lengthOfLastWord(char* s) {
    int pos=strlen(s)-1;
    int len=0;
    
    
    while(pos>=0&&*(s+pos)==' '){
        pos--;
    }
    
    while(pos>=0&&*(s+pos)!=' '){
        len++;
        pos--;
    }
    
    return len;
}
