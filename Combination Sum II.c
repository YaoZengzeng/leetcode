/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 
void dfs(int* candidates,int candidatesSize,int index,int *path,int pathLen,int target,int *columnSizes,int *returnSize,int **ans,int *cnt,int count) {
    int i,j;
    for(i=index;i<candidatesSize;i++){
        if(candidates[i]==target){
            if(i==index&&count==0){
                continue;
            }
            columnSizes[*returnSize]=pathLen+1;
            ans[*returnSize]=(int*)malloc((pathLen+1)*sizeof(int));
            for(j=0;j<pathLen;j++){
                ans[*returnSize][j]=path[j];
            }
            ans[*returnSize][pathLen]=candidates[i];
            (*returnSize)++;
        }else if(target>candidates[i]){
            if(i==index){
                if(count>0){
                    path[pathLen]=candidates[i];
                    dfs(candidates,candidatesSize,i,path,pathLen+1,target-candidates[i],columnSizes,returnSize,ans,cnt,count-1);
                }
            }else{
                path[pathLen]=candidates[i];
                dfs(candidates,candidatesSize,i,path,pathLen+1,target-candidates[i],columnSizes,returnSize,ans,cnt,cnt[i]-1);
            }
        }else{
            break;
        }
    }
    return;
}
int** combinationSum2(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    int i,j,t;
    int **ans;
    int path[1000],cnt[1000];
    
    *returnSize=0;
    if(candidatesSize<=0){
        return NULL;
    }
    
    ans=(int**)malloc(1000*sizeof(int*));
    (*columnSizes)=(int*)malloc(1000*sizeof(int));
    
    for(i=1;i<candidatesSize;i++){
        for(j=i;j>0;j--){
            if(candidates[j]<candidates[j-1]){
                t=candidates[j];
                candidates[j]=candidates[j-1];
                candidates[j-1]=t;
            }
        }
    }

    j=1;
    t=candidates[0];
    cnt[0]=1;
    for(i=1;i<candidatesSize;i++){
        if(candidates[i]==t){
            cnt[j-1]++;
            continue;
        }
        cnt[j]=1;
        candidates[j++]=t=candidates[i];
    }
    candidatesSize=j;
    
    dfs(candidates,candidatesSize,0,path,0,target,*columnSizes,returnSize,ans,cnt,cnt[0]);
    
    return ans;
}
