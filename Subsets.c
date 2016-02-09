/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 
void subsets2(int* nums,int numsSize,int* columnSizes,int* returnSize,int** ans){
    int i,n,j,flag,p;
    
    if(numsSize==1){
        columnSizes[*returnSize]=0;
        ans[*returnSize]=NULL;
        (*returnSize)++;
        columnSizes[*returnSize]=1;
        ans[*returnSize]=(int*)malloc(sizeof(int));
        ans[*returnSize][0]=nums[0];
        (*returnSize)++;
        return;
    }
    subsets2(nums,numsSize-1,columnSizes,returnSize,ans);
    
    n=*returnSize;
    for(i=0;i<n;i++){
        ans[*returnSize]=(int*)malloc((columnSizes[i]+1)*sizeof(int));
        columnSizes[(*returnSize)]=columnSizes[i]+1;
        flag=p=0;
        for(j=0;j<columnSizes[i];j++){
            if(nums[numsSize-1]<ans[i][j]&&flag==0){
                ans[*returnSize][p++]=nums[numsSize-1];
                flag=1;
            }
            ans[*returnSize][p++]=ans[i][j]; 
        }
        if(flag==0){
            ans[*returnSize][p++]=nums[numsSize-1];
        }
        (*returnSize)++;
    }
    return;
}
 
int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    int** ans;
    ans=(int**)malloc(10000*sizeof(int*));
    (*columnSizes)=(int*)malloc(10000*sizeof(int));
    *returnSize=0;
    subsets2(nums,numsSize,*columnSizes,returnSize,ans);
    return ans;
}
