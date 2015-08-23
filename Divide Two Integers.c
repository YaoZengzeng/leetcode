int divide(int dividend, int divisor) {
    int flag,i;
    long long Dividend,Divisor,result,times,tmpDivisor;
    
    Dividend=dividend;
    Divisor=divisor;
    
    if(Divisor==0){
        return INT_MAX;
    }
    if(Dividend==0){
        return 0;
    }
    
    
    if(Dividend>0&&Divisor<0||Dividend<0&&Divisor>0){
        flag=1;
    }else{
        flag=0;
    }
    
    Dividend=Dividend<0?-Dividend:Dividend;
    Divisor=Divisor<0?-Divisor:Divisor;
    
    result=0;
    while(Dividend-Divisor>=0){
        times=1;
        tmpDivisor=Divisor;
        for(i=1;;i++){
            if(Dividend-tmpDivisor<0){
                break;
            }
            Dividend-=tmpDivisor;
            result+=times;
            times+=times;
            tmpDivisor+=tmpDivisor;
        }
    }

    
    if(flag){
        result=-result;
    }else{
        result=result;   
    }
    
    if(result>INT_MAX){
        return INT_MAX;
    }else{
        return result;
    }
}
