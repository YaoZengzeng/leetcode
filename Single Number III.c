/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    int result=0,i,n;
    int* ans=(int*)malloc(2*sizeof(int));
    
    for(i=0;i<numsSize;i++){
        result=result^nums[i];
    }
    
    for(n=0;n<32;n++){
        if(result%2){
            break;
        }
        result=result/2;
    }
    
    ans[0]=ans[1]=0;
    for(i=0;i<numsSize;i++){
        if((nums[i]>>n)%2){
            ans[1]=ans[1]^nums[i];
        }else{
            ans[0]=ans[0]^nums[i];
        }
    }
    
    *returnSize=2;
    return ans;
}
