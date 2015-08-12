int climbStairs(int n) {
    long long array[2];
    int i,t;
    array[0]=1,array[1]=2;
    if(n==1) return 1;
    if(n==2) return 2;
    for(i=3;i<=n;i++){
        t=array[1];
        array[1]=array[1]+array[0];
        array[0]=t;
    }
    return array[1];
}
