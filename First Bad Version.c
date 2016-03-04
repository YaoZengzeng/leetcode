// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    long long l,r,m;
    l=1,r=n;
    
    while(l<r){
        m=(l+r)/2;
        if(isBadVersion(m)){
            r=m;
        }else{
            l=m+1;
        }
    }
    
    return (int)l;
}
