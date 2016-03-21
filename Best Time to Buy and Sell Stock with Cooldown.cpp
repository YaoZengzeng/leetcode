class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=0x80000000,pre_buy=0,pre_sell=0,sell=0;
        for(int i=0;i<prices.size();i++) {
            pre_buy=buy;
            buy=max(pre_buy,pre_sell-prices[i]);
            pre_sell=sell;
            sell=max(pre_sell,pre_buy+prices[i]);
        }
        return sell;
    }
};
