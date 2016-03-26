int dp[1000][1000];

int minDistance(char* word1, char* word2) {
    int min;
    if(strlen(word1)==0) {
        return strlen(word2);
    } else if (strlen(word2)==0) {
        return strlen(word1);
    }
    
    for(int i=0;i<=strlen(word2);i++) {
        dp[0][i]=i;
    }
    for(int i=0;i<=strlen(word1);i++) {
        dp[i][0]=i;
    }

    for(int i=0;i<strlen(word1);i++) {
        for(int j=0;j<strlen(word2);j++) {
            if(word1[i]==word2[j]) {
                dp[i+1][j+1]=dp[i][j];
            } else {
                min = dp[i+1][j]<dp[i][j+1] ? dp[i+1][j]:dp[i][j+1];
                min = min<dp[i][j] ? min:dp[i][j];
                dp[i+1][j+1]=min+1;
            }
        }
    }
    
    return dp[strlen(word1)][strlen(word2)];
    
}
