int dp[2][100000];

int numDistinct(char* s, char* t) {
    for(int i=0;i<=strlen(s);i++) {
        dp[0][i]=1;
    }
    dp[1][0]=0;
    for(int i=0;i<strlen(t);i++) {
        int cnt=0;
        for(int j=0;j<strlen(s);j++) {
            if(t[i]==s[j]) {
                cnt+=dp[0][j];
                dp[1][j+1]=cnt;
            } else {
                dp[1][j+1]=dp[1][j];
            }
        }
        for(int j=0;j<=strlen(s);j++) {
            dp[0][j]=dp[1][j];
        }
    }
    return dp[0][strlen(s)];
}
