int findPeakElement(int* nums, int numsSize) {
    int i,same;
    if(numsSize==1){
        return 0;
    }
    
    if(nums[numsSize-1]>nums[numsSize-2]){
        return numsSize-1;
    }
    
    same=0;
    for(i=0;i<numsSize-1;i++){
        if(nums[i]>nums[i+1]){
            if(same==0){
                return i;
            }
            same=-1;
        }else if(nums[i]==nums[i+1]){
            same=1;
        }else{
            same=0;
        }
    }
}
