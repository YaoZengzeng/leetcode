void moveZeroes(int* nums, int numsSize) {
    int i,p;
    for(i=p=0;i<numsSize;i++){
        if(nums[i]==0){
            continue;
        }else{
            nums[p++]=nums[i];
        }
    }
    for(;p<numsSize;p++){
        nums[p]=0;
    }
    return;
}
