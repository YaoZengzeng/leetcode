int findkth(int* a,int aSize,int*b,int bSize,int k) {
    int aPos,bPos;
    if(aSize>bSize){
        return findkth(b,bSize,a,aSize,k);
    }
    if(aSize==0){
        return b[k-1];
    }
    if(k==1){
        return a[0]<b[0] ? a[0] : b[0];
    }
    
    aPos = k/2<aSize ? k/2 : aSize;
    bPos = k-aPos;
    
    if(a[aPos-1]==b[bPos-1]){
        return a[aPos-1];
    }else if(a[aPos-1]<b[bPos-1]){
        return findkth(a+aPos,aSize-aPos,b,bSize,k-aPos);
    }else{
        return findkth(a,aSize,b+bPos,bSize-bPos,k-bPos);
    }
    
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    
    if((nums1Size+nums2Size)%2){
        return findkth(nums1,nums1Size,nums2,nums2Size,(nums1Size+nums2Size)/2+1)*1.0;
    }else{
        return (findkth(nums1,nums1Size,nums2,nums2Size,(nums1Size+nums2Size)/2)
            +findkth(nums1,nums1Size,nums2,nums2Size,(nums1Size+nums2Size)/2+1))/2.0;
    }
}
