void rotate(int* nums, int numsSize, int k) {
    int *p,n,i,t,j;
    int temp[100000];
    
    k=k%numsSize;
    n=numsSize;
    
    if(k==0){
        return ;
    }
    
    for(i=0;i<k;i++){
        temp[i]=nums[numsSize-k+i];
    }
    
    for(i=numsSize-k-1;i>=0;i--){
        nums[i+k]=nums[i];
    }
    
    for(i=0;i<k;i++){
        nums[i]=temp[i];
    }
    
    return ;
}
