/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** permuteUnique(int* nums, int numsSize, int* returnSize) {
    int i,t,retSize,j,k;
    int **ret,**r;
    int used[numsSize],cnt=0,flag;
    
    if(numsSize==1){
        r=(int**)malloc(sizeof(int*));
        r[0]=(int*)malloc(sizeof(int));
        r[0][0]=nums[0];
        *returnSize=1;
        return r;
    }
    
    
    *returnSize=0;
    for(i=0;i<numsSize;i++){
        flag=0;
        for(j=0;j<cnt;j++){
            if(nums[i]==used[j]){
               flag=1;
               break;
            }
        }
        if(flag){
            continue;
        }else{
            used[cnt++]=nums[i];
        }
        
        t=nums[0];
        nums[0]=nums[i];
        nums[i]=t;
        
        ret=permuteUnique(nums+1,numsSize-1,&retSize);
        *returnSize+=retSize;
        if(i==0){
            r=(int**)malloc(*returnSize*sizeof(int*));
            for(j=0;j<retSize;j++){
                r[j]=(int*)malloc(numsSize*sizeof(int));
                r[j][0]=nums[0];
                memcpy(&r[j][1],ret[j],sizeof(int)*(numsSize-1));
                free(ret[j]);
            }
            free(ret);
            k=j;
        }else{
            r=(int**)realloc(r,*returnSize*sizeof(int*));
            for(j=0;j<retSize;j++){
                r[k]=(int*)malloc(numsSize*sizeof(int));
                r[k][0]=nums[0];
                memcpy(&r[k][1],ret[j],sizeof(int)*(numsSize-1));
                free(ret[j]);
                k++;
            }
            free(ret);
        }
        
        t=nums[0];
        nums[0]=nums[i];
        nums[i]=t;
    }

    return r;
}
