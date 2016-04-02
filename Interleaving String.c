bool dp[1000][1000];

bool isInterleave(char* s1, char* s2, char* s3) {
    if(strlen(s1)+strlen(s2)!=strlen(s3)) {
        return false;
    }
    dp[0][0]=true;
    for(int n=1;n<=strlen(s3);n++) {
        int i,j;
        for(i=n,j=0; j<=n; i--,j++) {
            if(i>strlen(s1) || j>strlen(s2)) {
                continue;
            }
            dp[i][j]=false;
            if(i>0&&s1[i-1]==s3[n-1]&&dp[i-1][j]||j>0&&s2[j-1]==s3[n-1]&&dp[i][j-1]) {
                dp[i][j]=true;
            }
        }
    }
    return dp[strlen(s1)][strlen(s2)];
}
