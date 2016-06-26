bool match(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return true;
    }
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return true;
    }
    
    return false;
}
char* reverseVowels(char* s) {
    int start = 0, end = strlen(s) - 1;
    char c;
    
    while(1){
        while(start < strlen(s) && !match(s[start])) {
            start++;
        }
        while(end >= 0 && !match(s[end])) {
            end--;
        }
        if (start >= end) {
            break;
        }
        
        c = s[start];
        s[start] = s[end];
        s[end] = c;
        
        start++;
        end--;
    }
    
    return s;
}
