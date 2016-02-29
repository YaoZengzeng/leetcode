bool containsNearbyAlmostDuplicate(int* nums, int numsSize, int k, int t) {
    int i,j,end,n;
    if(numsSize==0||k==0){
        return false;
    }
    
    n= k<(numsSize-1)? k:(numsSize-1);
    for(i=1;i<=n;i++){
        for(j=i-1;j>=0;j--){
            if(abs(nums[i]-nums[j])<=t){
                if(nums[i]>nums[j]){
                    if(nums[i]>0&&nums[j]<0&&nums[i]-nums[j]<=0){
                        continue;
                    }
                }else {
                    if(nums[j]>0&&nums[i]<0&&nums[j]-nums[i]<=0){
                        continue;
                    }
                }
                return true;
            }
        }
    }
    end=k+1;
    while(end<numsSize){
        j=end-1;
        while(end-j<=k){
            if(abs(nums[end]-nums[j])<=t){
                if(nums[end]>nums[j]){
                    if(nums[end]>0&&nums[j]<0&&nums[end]-nums[j]<=0){
                        goto L;
                    }
                }else {
                    if(nums[j]>0&&nums[end]<0&&nums[j]-nums[end]<=0){
                        goto L;
                    }
                }
                return true;
            }
            L:  j--;
        }
        end++;
    }
    
    return false;
}
