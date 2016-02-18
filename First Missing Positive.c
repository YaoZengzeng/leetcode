int firstMissingPositive(int* nums, int numsSize) {
    int vis[10000];
    int i;
    
    for(i=1;i<=numsSize;i++){
        vis[i]=0;
    }
    
    for(i=0;i<numsSize;i++){
        if(nums[i]>0&&nums[i]<=numsSize){
            vis[nums[i]]=1;
        }
    }
    
    for(i=1;i<=numsSize;i++){
        if(vis[i]==0){
            return i;
        }
    }
    return numsSize+1;
}
