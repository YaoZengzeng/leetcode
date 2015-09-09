int longestValidParentheses(char* s) {
    char stack[strlen(s)];
    int  posStack[strlen(s)],pos=0,i,max;
    
    for(i=0;i<strlen(s);i++){
        if(pos==0||s[i]=='('){
            stack[pos]=s[i];
            posStack[pos]=i;
            pos++;
        }else{
            if(stack[pos-1]=='('){
                pos--;
            }else{
                stack[pos]=s[i];
                posStack[pos]=i;
                pos++;
            }
        }
    }
    
    if(pos==0){
        return strlen(s);
    }
    max=posStack[0]-0;
    for(i=1;i<pos;i++){
        max=posStack[i]-posStack[i-1]-1>max?posStack[i]-posStack[i-1]-1:max;
    }
    if(strlen(s)-posStack[pos-1]-1>max){
        max=strlen(s)-posStack[pos-1]-1;
    }
    return max;
}
