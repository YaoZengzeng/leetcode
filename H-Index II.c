int hIndex(int* citations, int citationsSize) {
    int i,n;
    if(citationsSize==0){
        return 0;
    }
    n=citationsSize;
    i=citationsSize-1;
    while(i>=0){
        if(citations[i]<n){
            if(citationsSize-1-i>=n){
                return n;
            }else{
                n--;
            }
            continue;
        }
        i--;
    }
    
    return n;
}
