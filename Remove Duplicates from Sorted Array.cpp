int removeDuplicates(int* nums, int numsSize) {
    int nowNum=nums[0],i,pos=1;
    
    if(numsSize<=0) return numsSize;
    for(i=1;i<numsSize;i++){
        if(nums[i]==nowNum){
            continue;
        }else{
            nums[pos++]=nowNum=nums[i];
        }
    }
    return pos;
}
