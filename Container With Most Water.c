int maxArea(int* height, int heightSize) {
    int beg=0,end=heightSize-1;
    int max,smaller;
    
    smaller=height[beg]<height[end]?height[beg]:height[end];
    max=(end-beg)*smaller;
    while(beg<end){
        smaller=height[beg]<height[end]?height[beg]:height[end];
        if((end-beg)*smaller>max){
            max=(end-beg)*smaller;
        }
        if(height[beg]<height[end]){
            beg++;
        }else{
            end--;
        }
    }
    return max;
}
