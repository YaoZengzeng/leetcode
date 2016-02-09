/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 
void subsetsWithDup2(int* nums,int numsSize,int* columnSizes,int* returnSize,int** ans){
    int i,n,j,flag,p,cnt,count;
    
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
    subsetsWithDup2(nums,numsSize-1,columnSizes,returnSize,ans);
    
    n=*returnSize;
    
    cnt=0;
    for(i=0;i<columnSizes[n-1];i++){
        if(ans[n-1][i]==nums[numsSize-1]){
            cnt++;
        }    
    }
    
    for(i=n-1;i>=0;i--){
        count=0;
        for(j=0;j<columnSizes[i];j++){
            if(ans[i][j]==nums[numsSize-1]){
                count++;
            }
        }
        if(count<cnt){
            break;
        }
        
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
 

int** subsetsWithDup(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    int i,j,t;
    int **ans;
    for(i=1;i<numsSize;i++){
        for(j=i;j>0;j--){
            if(nums[j]<nums[j-1]){
                t=nums[j];
                nums[j]=nums[j-1];
                nums[j-1]=t;
            }else{
                break;
            }
        }
    }

    ans=(int**)malloc(10000*sizeof(int*));
    (*columnSizes)=(int*)malloc(10000*sizeof(int));
    *returnSize=0;
    subsetsWithDup2(nums,numsSize,*columnSizes,returnSize,ans);
    return ans;    
    
}
