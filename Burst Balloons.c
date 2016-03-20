int dp[1000][1000];
int maxCoins(int* nums, int numsSize) {
    if(numsSize==1){
        return nums[0];
    }
    for(int i=0;i<numsSize;i++) {
        if(i==0) {
            dp[i][i]=nums[i]*nums[i+1];
        } else if(i==numsSize-1){
            dp[i][i]=nums[i-1]*nums[i];
        } else {
            dp[i][i]=nums[i-1]*nums[i]*nums[i+1];
        }
    }
    for(int i=1;i<numsSize;i++) {
        for(int j=0;j+i<numsSize;j++) {
            int left,right;
            if(j==0){
                left=1;
            } else {
                left=nums[j-1];
            }
            if(j+i==numsSize-1){
                right=1;
            } else {
                right=nums[j+i+1];
            }
            for(int k=j;k<=j+i;k++){
                if(k==j) {
                    dp[j][j+i]=nums[k]*left*right+dp[k+1][j+i];
                } else if(k==j+i) {
                    int t=dp[j][k-1]+nums[k]*left*right;
                    dp[j][j+i] = dp[j][j+i]>t ? dp[j][j+i]:t;
                } else {
                    int t=dp[j][k-1]+nums[k]*left*right+dp[k+1][j+i];
                    dp[j][j+i] = dp[j][j+i]>t ? dp[j][j+i]:t;
                }
            }
        }
    }
    
    return dp[0][numsSize-1];
}
