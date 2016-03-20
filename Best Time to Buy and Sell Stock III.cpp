class Solution {
public:
    int maxProfitOnce(vector<int>& prices,int pos) {
        if(pos==prices.size()) {
            return 0;
        }
        int min=prices[pos];
        int max=0;
        for(int i=pos+1;i<prices.size();i++) {
            if(prices[i]<=min) {
                min=prices[i];
            } else {
                max = max>(prices[i]-min)? max:(prices[i]-min);
            }
        }
        return max;
    }
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) {
            return 0;
        }
        int max=0;
        int min=prices[0];
        for(int i=1;i<prices.size();i++) {
            if(prices[i]<=min) {
                min=prices[i];
            } else {
                int temp=prices[i]-min;
                temp+=maxProfitOnce(prices,i+1);
                max = max>temp? max:temp;
            }
        }
        return max;
    }
};
