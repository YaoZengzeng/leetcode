int missingNumber(int* nums, int numsSize) {
    int i,t;
    for(i=0;i<numsSize;i++){
        while(nums[i]!=i&&nums[i]!=numsSize){
            t=nums[nums[i]];
            nums[nums[i]]=nums[i];
            nums[i]=t;
        }
    }
    for(i=0;i<numsSize;i++){
        if(nums[i]!=i){
            return i;
        }
    }
    
    return numsSize;
}
