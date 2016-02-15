char* multiply(char* num1, char* num2) {
    int i,j,t,len,carry,x,cnt,min;
    char m[10000];
    char *a,c;
    
    a=(char*)malloc(10000*sizeof(char));
    a[0]='0';
    len=1;
    if(strlen(num1)==1&&num1[0]=='0'||strlen(num2)==1&&num2[0]=='0'){
        a[len]='\0';
        return a;
    }
    
    for(i=strlen(num1)-1;i>=0;i--){
        t=num1[i]-'0';
        if(t==0){
            continue;
        }
        carry=0;
        
        for(cnt=0;cnt<(strlen(num1)-1-i);cnt++){
            m[cnt]='0';
        }
        
        for(j=strlen(num2)-1;j>=0;j--){
            m[cnt++]=(t*(num2[j]-'0')+carry)%10+'0';
            carry=(t*(num2[j]-'0')+carry)/10;
        }
        if(carry){
            m[cnt++]=carry+'0';
        }
        
        carry=0;
        if(cnt>len){
            min=len;
        }else{
            min=cnt;
        }
        for(j=0;j<min;j++){
            t=(a[j]-'0'+m[j]-'0'+carry)%10;
            carry=(a[j]-'0'+m[j]-'0'+carry)/10;
            a[j]=t+'0';
        }
        if(min==len){
            for(j=min;j<cnt;j++){
                t=(m[j]-'0'+carry)%10;
                carry=(m[j]-'0'+carry)/10;
                a[j]=t+'0';
            }
            len=cnt;
        }else{
            for(j=min;j<len;j++){
                t=(a[j]-'0'+carry)%10;
                carry=(a[j]-'0'+carry)/10;
                a[j]=t+'0';
            }
        }
        if(carry){
            a[len++]=carry+'0';
        }
        
    }
    
    for(i=0;i<len/2;i++){
        c=a[i];
        a[i]=a[len-1-i];
        a[len-1-i]=c;
    }
    a[len]='\0';
    
    return a;
}
