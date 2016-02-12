int maxSubArray(int* nums, int numsSize) {
    int max,min,sum;
    int i;
    
    max=sum=nums[0];
    min = sum<0 ? sum : 0;
    for(i=1;i<numsSize;i++){
        sum+=nums[i];
        max = (sum-min)>max ? (sum-min) : max;
        min = sum<min ? sum : min;
    }
    return max;
}
