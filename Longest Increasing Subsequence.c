int less[100000];
int lengthOfLIS(int* nums, int numsSize) {
    int i,j,max;

    for(i=0;i<numsSize;i++) {
        max=0;
        for(j=i-1;j>=0;j--) {
            if(nums[i]>nums[j]&&less[j]>max) {
                max=less[j];
            }
        }
        less[i]=max+1;
    }
    
    max=0;
    for(i=0;i<numsSize;i++) {
        max = max>less[i]? max:less[i];
    }
    
    return max;
}
