int findDuplicate(int* nums, int numsSize) {
    int l,r,m,cnt;
    int i;
    l=1,r=numsSize-1;
    while(l<r){
        m=(l+r)/2;
        cnt=0;
        for(i=0;i<numsSize;i++){
            if(nums[i]<=m){
                cnt++;
            }
        }
        if(cnt>m){
            r=m;
        }else{
            l=m+1;
        }
    }
    return l;
}
