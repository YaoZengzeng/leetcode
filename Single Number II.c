int singleNumber(int* nums, int numsSize) {
    int i,j,bit[32],t;
    
    for(i=0;i<32;i++){
        bit[i]=0;
    }
    
    for(i=0;i<numsSize;i++){
        t=nums[i];
        for(j=0;j<32;j++){
            if(t%2){
                bit[j]++;
            }
            t=t>>1;
        }
    }
    
    t=0;
    for(i=31;i>=0;i--){
        t=t*2+bit[i]%3;
    }
    
    return t;
}
