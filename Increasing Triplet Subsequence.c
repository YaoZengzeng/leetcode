bool increasingTriplet(int* nums, int numsSize) {
    int min,mid,max;
    int i=1;
    min=mid=max=0x7fffffff;
    while(i<numsSize){
        if(nums[i]>nums[i-1]){
            if(nums[i]>mid){
                return true;
            }
            mid=nums[i];
            if(nums[i-1]<min){
                min=nums[i-1];
            }
        }else if(nums[i]<mid && nums[i]>min){
            mid=nums[i];
        }
        i++;
    }
    
    return false;
}
