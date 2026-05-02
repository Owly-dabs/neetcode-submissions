class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = 0;
        int max = 0;
        int profit = 0;
        for (int i=1;i<prices.size();i++) {
            if (prices[i]>prices[max]) {
                max = i;
            }
            if (prices[i]<prices[min]) {
                min = i;
                max = i;
            }
            if (prices[max] - prices[min] > profit) {
                profit = prices[max] - prices[min];
            }
        }
        return profit;
    }
};
