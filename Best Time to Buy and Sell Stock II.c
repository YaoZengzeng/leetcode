int maxProfit(int* prices, int pricesSize) {
    int sum,min,max,i;
    
    sum=0;
    i=1;
    
    while(i<pricesSize){
        while(i<pricesSize && prices[i-1]>=prices[i]){
            i++;
        }
        min=max=prices[i-1];
        while(i<pricesSize){
            if(max!=min && prices[i]<prices[i-1]){
                sum+=(max-min);
                min=max=prices[i];
                break;
            }else if(prices[i]>max){
                max=prices[i];
            }
            i++;
        }
        sum+=(max-min);
    }
    
    return sum;
}
