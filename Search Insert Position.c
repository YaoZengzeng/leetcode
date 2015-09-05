int searchInsert(int* nums, int numsSize, int target) {
    int reverse=0,i,t;
    int beg,end,mid;
    
    if(numsSize==0){
        return 0;
    }
    
    if(nums[numsSize-1]<nums[0]){
        for(i=0;i<numsSize;i++){
            t=nums[i];
            nums[i]=nums[numsSize-1-i];
            nums[numsSize-1-i]=t;
        }
        reverse=0;
    }
    
    beg=0,end=numsSize-1;
    while(beg<=end){
        mid=(beg+end)/2;
        if(nums[mid]==target){
            return mid;
        }else if(nums[mid]<target){
            beg=mid+1;
        }else{
            end=mid-1;
        }
    }
    
    if(beg!=mid){
        if(reverse){
            return target-beg-1;
        }else{
            return beg;
        }
    }else{
        if(reverse){
            return target-mid-1;
        }else{
            return mid;
        }
    }
}
