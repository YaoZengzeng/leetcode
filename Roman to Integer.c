int getVal(char c) {
    char R[]="IVXLCDM";
    int  V[]={1,5,10,50,100,500,1000};
    
    for(int i=0;i<strlen(R);i++){
        if(c==R[i]){
            return V[i];
        }
    }
}

int romanToInt(char* s) {
    char prev=s[0];
    int ans=getVal(s[0]);
    
    for(int i=1;i<strlen(s);i++){
        if(getVal(prev)<getVal(s[i])){
            ans=ans-2*getVal(prev)+getVal(s[i]);
        }else{
            ans+=getVal(s[i]);
        }
        prev=s[i];
    }
    
    return ans;
}
