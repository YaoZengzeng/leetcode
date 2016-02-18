int maxProfit(int* prices, int pricesSize) {
    int max,min,i;
    
    min=prices[0];
    max=0;
    for(i=1;i<pricesSize;i++){
        if(prices[i]-min>max){
            max=prices[i]-min;
        }
        if(prices[i]<min){
            min=prices[i];
        }
    }
    return max;
}
