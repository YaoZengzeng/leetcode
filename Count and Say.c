char* countAndSay(int n) {
    char* ans=(char*)malloc(10000);
    char  tmp[10000],integer[20],t;
    int cnt=0,i,j,k,sum,num,digits;
    
    ans[0]='1';
    ans[1]='\0';
    cnt=1;
    if(n==1){
        return ans;
    }
    
    for(i=1;i<n;i++){
        strcpy(tmp,ans);
        j=sum=num=0;
        while(j<=cnt){
            if(j==0||j>0&&tmp[j]==tmp[j-1]){
                num++;
                j++;
            }else{
                digits=0;
                while(num){
                    integer[digits++]=num%10+'0';
                    num/=10;
                }
                for(k=0;k<digits/2;k++){
                    t=integer[k];
                    integer[k]=integer[digits-1-k];
                    integer[digits-1-k]=t;
                }
                integer[digits]='\0';
                strcpy(ans+sum,integer);
                sum+=digits;
                ans[sum++]=tmp[j-1];
                num=1;
                j++;
            }
        }
        ans[sum]='\0';
        cnt=sum;
    }
    return ans;
}
