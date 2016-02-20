int singleNumber(int* nums, int numsSize) {
    int i,t;
    t=nums[0];
    for(i=1;i<numsSize;i++){
        t^=nums[i];
    }
    
    return t;
}
