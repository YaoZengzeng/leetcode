int rob(int* nums, int numsSize) {
    int y1,y2,n1,n2,i;
    if(numsSize==1){
        return nums[0];
    }
    
    y1=nums[0];
    n1=0;
    
    for(i=1;i<numsSize;i++){
      n2 = y1>n1 ? y1 : n1;
      y2 = n1+nums[i];
      y1 = y2;
      n1 = n2;
    }
    
    return y1>n1 ? y1 : n1;
}
