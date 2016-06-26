char* reverseString(char* s) {
    int i;
    char c;
    
    for(i = 0; i < strlen(s) / 2; i++) {
        c = s[i];
        s[i] = s[strlen(s) - 1 - i];
        s[strlen(s) - 1 - i] = c;
    }
    
    return s;
}
