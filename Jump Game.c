bool canJump(int* nums, int numsSize) {
    int i,max;
    max=0;
    
    if(numsSize==1){
        return true;
    }
    
    for(i=0;i<=max;i++){
        if(i+nums[i]>max){
            max=i+nums[i];
            if(max>=numsSize-1){
                return true;
            }
        }
    }
    
    return false;
}
