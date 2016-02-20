int findMin(int* nums, int numsSize) {
    int l,m,r,beg;
    
    l=0,r=numsSize-1;
    while(nums[l]==nums[r]){
        l++;
        if(l==numsSize){
            return nums[0];
        }
    }
    
    if(nums[l]<nums[r]){
        return nums[l];
    }
    
    beg=l;
    while(l<=r){
        m=(l+r)/2;
        while(nums[m-1]==nums[m]){
            m--;
        }
        if(nums[m]<nums[m-1]){
            return nums[m];
        }
        if(nums[m]>=nums[beg]){
            while(nums[m]==nums[m+1]){
                m++;
            }
            l=m+1;
        }else{
            r=m-1;
        }
    }
    
}
