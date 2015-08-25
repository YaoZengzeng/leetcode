/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize) {
    int i,t,retSize,j,k;
    int **ret[numsSize],**r;
    
    if(numsSize==1){
        r=(int**)malloc(sizeof(int*));
        r[0]=(int*)malloc(sizeof(int));
        r[0][0]=nums[0];
        *returnSize=1;
        return r;
    }
    
    for(i=0;i<numsSize;i++){
        t=nums[0];
        nums[0]=nums[i];
        nums[i]=t;
        if(numsSize==3)
        printf("nums[0]=%d\n",nums[0]);
        
        ret[i]=permute(nums+1,numsSize-1,&retSize);
        if(i==0){
            r=(int**)malloc(retSize*sizeof(int*)*numsSize);
            for(j=0;j<retSize;j++){
                r[j]=(int*)malloc(numsSize);
                r[j][0]=nums[0];
                memcpy(&r[j][1],ret[i][j],sizeof(int)*(numsSize-1));
                free(ret[i][j]);
            }
            free(ret[i]);
            k=j;
        }else{
            for(j=0;j<retSize;j++){
                r[k]=(int*)malloc(numsSize);
                r[k][0]=nums[0];
                memcpy(&r[k][1],ret[i][j],sizeof(int)*(numsSize-1));
                free(ret[i][j]);
                k++;
            }
            free(ret[i]);
        }
        
        t=nums[0];
        nums[0]=nums[i];
        nums[i]=t;
    }
    *returnSize=retSize*numsSize;
    return r;
}
