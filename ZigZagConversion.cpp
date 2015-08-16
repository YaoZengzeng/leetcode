char* convert(char* s, int numRows) {
    int i,j,k,pos,dir;
    char* a=(char*)malloc(strlen(s)+1);
    pos=dir=0;
    
    if(numRows==1) return s;
    for(i=1;i<=numRows;i++){
        k=1;
        dir=0;
        for(j=0;j<strlen(s);j++){
            if(k==i){
                *(a+pos++)=*(s+j);
            }
            if(dir){
                k--;
            }else{
                k++;
            }
            if(k==numRows){
                dir=1;
            }
            if(k==1){
                dir=0;
            }
        }
    }
    a[strlen(s)]='\0';
    strcpy(s,a);
}
