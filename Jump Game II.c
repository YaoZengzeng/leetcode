int jump(int* nums, int numsSize) {
    int i,j,min;
    nums[numsSize-1]=0;
    for(i=numsSize-2;i>=0;i--){
        if(nums[i]==0){
            nums[i]=0xffffff;
        }else if(i+nums[i]>=numsSize-1){
            nums[i]=1;
        }else{
            min=0x7fffffff;
            for(j=nums[i];j>0;j--){
                if(min>nums[i+j]){
                    min=nums[i+j];
                    if(min==1){
                        break;
                    }
                }
            }
            nums[i]=min+1;
        }
    }
    
    return nums[0];
    
}
