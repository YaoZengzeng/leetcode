/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
void restoreIpAddresses2(char* s,int p1,char* ip,int p2,int left,char** ans,int* returnSize) {
    int val=0,i;
    if(left==1&&p1<strlen(s)){
        if(s[p1]=='0'&&strlen(s)-p1>1){
            return 0;
        }
        for(i=p1;i<strlen(s);i++){
            val=val*10+s[i]-'0';
            if(val>255){
                return;
            }
        }
        for(i=p1;i<strlen(s);i++){
            ip[p2++]=s[i];
        }
        ip[p2]='\0';
        ans[*returnSize]=(char*)malloc((strlen(ip)+1)*sizeof(char));
        strcpy(ans[*returnSize],ip);
        (*returnSize)++;
        return;
    }
    
    if(s[p1]=='0'){
        ip[p2++]=s[p1];
        ip[p2]='.';
        restoreIpAddresses2(s,p1+1,ip,p2+1,left-1,ans,returnSize);
        return;
    }
    
    for(i=p1;i<strlen(s);i++){
        val=val*10+s[i]-'0';
        if(val<=255){
            ip[p2++]=s[i];
            ip[p2]='.';
            restoreIpAddresses2(s,i+1,ip,p2+1,left-1,ans,returnSize);
        }else{
            break;
        }
    }
    return;
}


char** restoreIpAddresses(char* s, int* returnSize) {
    char** ans,ip[40];
    
    ans=(char**)malloc(1000*sizeof(char*));
    *returnSize=0;
    restoreIpAddresses2(s,0,ip,0,4,ans,returnSize);
    return ans;
}
