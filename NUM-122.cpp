class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
          int minus = prices[i] - prices[i-1];
          if (minus > 0)
            profit += minus; 
        }
        return profit;
    }
};