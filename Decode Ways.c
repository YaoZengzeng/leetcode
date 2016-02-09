int numDecodings(char* s) {
    int val,i,ans[10000];
    
    if(strlen(s)==0){
        return 0;
    }
    
    ans[0]=1;
    if(s[0]=='0'){
        ans[1]=0;
    }else{
        ans[1]=1;
    }
    for(i=2;i<=strlen(s);i++){
        if(s[i-1]=='0'){
            ans[i]=0;
        }else{
            ans[i]=ans[i-1];
        }
        if(s[i-2]!='0'){
            val=s[i-2]-'0';
            val=val*10+s[i-1]-'0';
            if(val>=1&&val<=26){
                ans[i]+=ans[i-2];
            }
        }
    }
    
    return ans[strlen(s)];
}
