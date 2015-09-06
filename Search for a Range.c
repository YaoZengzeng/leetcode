/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int beg,end,mid,beg1,end1,mid1,flag=0;
    int *ans=(int*)malloc(sizeof(int)*2);
    
    beg=0,end=numsSize-1;
    while(beg<=end){
        mid=(beg+end)/2;
        if(nums[mid]==target){
            flag=1;
            break;
        }else if(nums[mid]<target){
            beg=mid+1;
        }else{
            end=mid-1;
        }
    }
    
    if(flag){
        beg1=beg,end1=mid;
        while(beg1<end1){
            mid1=(beg1+end1)/2;
            if(nums[mid1]==target){
                end1=mid1;
            }else{
                beg1=mid1+1;
            }
        }
        ans[0]=beg1;
        beg1=mid,end1=end;
        while(beg1<end1){
        
            mid1=(beg1+end1)/2;
            if(nums[mid1]==target){
                beg1=mid1+1;
            }else{
                end1=mid1-1;
            }
        }
        
        if(nums[beg1]!=target){
        	beg1--;
        }
    	ans[1]=beg1;
        *returnSize=2;
    }else{
        ans[0]=ans[1]=-1;
        *returnSize=2;
    }
    return ans;
}
