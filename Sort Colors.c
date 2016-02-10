void sortColors(int* nums, int numsSize) {
    int p1,p2,p3;
    int i,t;
    
    p1=p2=0;
    p3=numsSize-1;
    
    while(p2<=p3){
        if(p1==p2&&nums[p1]==0){
            p1++;
            p2++;
        }else if(nums[p2]==0){
            nums[p2]=nums[p1];
            nums[p1++]=0;
        }else if(nums[p2]==2){
            if(nums[p3]==2){
                p3--;
            }else{
                nums[p2]=nums[p3];
                nums[p3--]=2;
            }
        }else{
            p2++;
        }
    }
    
    return;
}
