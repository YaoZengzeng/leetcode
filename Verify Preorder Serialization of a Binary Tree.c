bool isValidSerialization2(char* preorder,int*p) {
    int flag=0;
    if(preorder[*p]=='\0'){
        return false;
    }
    
    while(preorder[*p]!=','&&preorder[*p]!='\0'){
        if(preorder[*p]=='#'){
            flag=1;
        }
        (*p)++;
    }
    
    if(preorder[*p]==','){
        (*p)++;
    }
    
    if(flag){
        return true;
    }
    
    if(isValidSerialization2(preorder,p)&&isValidSerialization2(preorder,p)){
        return true;
    }else{
        return false;
    }
}

bool isValidSerialization(char* preorder) {
    int p=0;
    if(isValidSerialization2(preorder,&p)==false){
        return false;
    }
    if(preorder[p]=='\0'){
        return true;
    }else{
        return false;
    }
}
