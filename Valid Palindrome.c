bool isPalindrome(char* s) {
    int i,j;
    i=0;
    j=strlen(s)-1;
    while(i<j){
        while(!isalnum(s[i])&&i<strlen(s)){
            i++;
        }
        while(!isalnum(s[j])&&j>=0){
            j--;
        }
        if(isdigit(s[i])){
            if(s[i]!=s[j]){
                return false;
            }else{
                i++;
                j--;
            }
        }else{
            if(tolower(s[i])!=tolower(s[j])){
                return false;
            }else{
                i++;
                j--;
            }
        }
    }
    return true;
}
