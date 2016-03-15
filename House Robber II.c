int rob(int* nums, int numsSize) {
    int y1,y2,n1,n2;
    int max1,max2;
    
    y1=nums[0],n1=0;
    for(int i=1;i<numsSize-1;i++){
        y2=n1+nums[i];
        n2= y1>n1 ? y1:n1;
        y1=y2;
        n1=n2;
    }
    max1= y1>n1 ? y1:n1;
    
    y1=n1=0;
    for(int i=1;i<numsSize;i++){
        y2=n1+nums[i];
        n2= y1>n1 ? y1:n1;
        y1=y2;
        n1=n2;
        
    }
    max2= y1>n1 ? y1:n1;
    return max2>max1 ? max2:max1;
}
