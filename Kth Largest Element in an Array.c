int findKthLargest(int* nums, int numsSize, int k) {
    int i,j,t,n,max,pos;
    
    for(i=1;i<numsSize;i++){
        n=i;
        while(n>0&&nums[n]>nums[(n-1)/2]){
            t=nums[n];
            nums[n]=nums[(n-1)/2];
            nums[(n-1)/2]=t;
            n=(n-1)/2;
        }
    }
    for(i=1;i<k;i++){
        t=nums[0];
        nums[0]=nums[numsSize-i];
        nums[numsSize-i]=t;
        
        n=0;
        while(n<numsSize-i){
            max=nums[n];
            if(n*2+1<numsSize-i&&max<nums[n*2+1]){
                max= nums[n*2+1];
                pos=n*2+1;
            }
            if(n*2+2<numsSize-i&&max<nums[n*2+2]){
                max= nums[n*2+2];
                pos=n*2+2;
            }
            if(max==nums[n]){
                break;
            }
            t=nums[n];
            nums[n]=nums[pos];
            nums[pos]=t;
            n=pos;
        }
        
    }
    
    return nums[0];
}
