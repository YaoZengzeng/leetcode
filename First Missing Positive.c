int firstMissingPositive(int* nums, int numsSize) {
    int i,t;
    
    for(i=0;i<numsSize;i++){
        while(nums[i]!=(i+1)&&nums[i]>0&&nums[i]<=numsSize){
            if(nums[nums[i]-1]==nums[i]){
                break;
            }
            t=nums[nums[i]-1];
            nums[nums[i]-1]=nums[i];
            nums[i]=t;
        }
    }
    
    for(i=0;i<numsSize;i++){
        if(nums[i]!=(i+1)){
            return i+1;
        }
    }
    return numsSize+1;
}
