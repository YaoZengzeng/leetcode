char* intToRoman(int num) {
    char R[]="MDCLXVI";
    int  V[]={1000,500,100,50,10,5,1};
    char* ans=(char*)malloc(40);
    int  cnt=0;

    for(int i=0;i<7;i++){
        int n=num/V[i];
        for(int j=0;j<n;j++){
            ans[cnt++]=R[i];
        }
        num-=(n*V[i]);
        if(i!=6&&num>=(V[i]-V[i/2*2+2])){
            ans[cnt++]=R[i/2*2+2];
            ans[cnt++]=R[i];
            num-=(V[i]-V[i/2*2+2]);
        }
    }
    ans[cnt]='\0';
    return ans;
}
