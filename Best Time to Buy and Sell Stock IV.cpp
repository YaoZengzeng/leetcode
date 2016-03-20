class Solution {
public:
    int solveMaxProfit(vector<int>& prices) {
        int ans=0;
        for(int i=1;i<prices.size();i++) {
            if(prices[i]-prices[i-1]>0) {
                ans+=prices[i]-prices[i-1];
            }
        }
        return ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size()==0) {
            return 0;
        } else if(k>=prices.size()) {
            return solveMaxProfit(prices);
        }
        int global[k+1]={0};
        int local[k+1]={0};
        for(int i=1;i<prices.size();i++) {
            int diff=prices[i]-prices[i-1];
            for(int j=k;j>=1;j--) {
                local[j]=max(global[j-1]+max(0,diff),local[j]+diff);
                global[j]=max(global[j],local[j]);
            }
        }
        return global[k];
    }
};
