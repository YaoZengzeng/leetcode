int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int i,sum,p;
    sum=0;
    for(i=0;i<gasSize;i++){
        gas[i]=gas[i]-cost[i];
        sum+=gas[i];
    }
    
    if(sum<0){
        return -1;
    }
    
    i=0;
    while(i<gasSize) {
        sum=0;
        p=i;
        while(i<gasSize&&sum>=0) {
            sum+=gas[i++];
        }
        if(sum>=0){
            return p;
        }
    }
    return -1;
}
