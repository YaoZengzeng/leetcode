bool search(int* nums, int numsSize, int target) {
    int l,m,r;
    l=0,r=numsSize-1;
    
    if(nums[l]==nums[r]){
        while(l<r){
            if(nums[l]==nums[r]){
                l++;
            }else{
                break;
            }
        }
    }
    
    if(nums[l]>nums[r]){
        while(l<r){
            if(l==r-1){
                break;
            }
            m=(l+r)/2;
            if(nums[m]>=nums[l]){
                l=m;
            }else{
                r=m;
            }
        }
        if(target>=nums[0]&&target<=nums[l]){
            r=l,l=0;
        }
        if(target>=nums[r]&&target<=nums[numsSize-1]){
            l=r,r=numsSize-1;
        }
    }
    
    while(l<=r){
        m=(l+r)/2;
        if(target==nums[m]){
            return true;
        }else if(target<nums[m]){
            r=m-1;
        }else{
            l=m+1;
        }
    }
    
    return false;    
}
