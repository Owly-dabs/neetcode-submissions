class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;
        
        int out = 0;
        int max = prices[0];
        int min = prices[0];

        for (int p : prices) {
            if (p - min > out) {
                max = p;
                out = max - min;
            } else if (p < min) {
                min = p;
            }
        }

        return out;
    }
};
