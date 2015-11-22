/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int maxLen=digitsSize+1;
    int *ans=(int*)malloc(sizeof(int)*(maxLen));
    int carry=1,i;
    
    for(i=0;i<digitsSize;i++){
        ans[maxLen-1-i]=(digits[digitsSize-1-i]+carry)%10;
        carry=(digits[digitsSize-1-i]+carry)/10;
    }
    if(carry){
        ans[0]=carry;
        *returnSize=maxLen;
        return ans;
    }else{
        *returnSize=maxLen-1;
        return ans+1;
    }
}
