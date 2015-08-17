int removeDuplicates(int* nums, int numsSize) {
    int i,cnt,pos=0;
    int p1,p2;
    
    if(numsSize<=0) return numsSize;
    
    p1=p2=0;
    while(p2<numsSize){
        cnt=0;
        while(p2<numsSize&&nums[p1]==nums[p2]){
            p2++;
            cnt++;
        }
        cnt= cnt>2?2:cnt;
        for(i=0;i<cnt;i++){
            nums[pos++]=nums[p1];
        }
        p1=p2;
    }
    
    return pos;
}
