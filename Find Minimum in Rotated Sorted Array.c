int findMin(int* nums, int numsSize) {
    int l,m,r;
    
    if(nums[0]<nums[numsSize-1]||numsSize==1){
        return nums[0];
    }
    
    if(nums[numsSize-1]<nums[numsSize-2]){
        return nums[numsSize-1];
    }
    
    l=0,r=numsSize-1;
    while(l<=r){
        m=(l+r)/2;
        if(nums[m]<nums[m-1]&&nums[m]<nums[m+1]){
            return nums[m];
        }
        if(nums[m]>nums[0]){
            l=m+1;
        }else{
            r=m;
        }
    }
}
