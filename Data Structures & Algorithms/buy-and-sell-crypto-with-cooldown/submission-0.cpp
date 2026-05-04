#include <algorithm>
class Solution {
public:
    int m;
    int maxProfit(vector<int>& prices) {
        m = prices.size();
        vector<vector<int>> memo(m+1, vector<int>(m, -1));
        return dp(prices, m, 0, memo);
    }

    int dp(vector<int>& prices, int buy_i, int pointer, vector<vector<int>>& memo) {
        // base case
        if (pointer >= m) {
            return 0;
        }
        
        if (memo[buy_i][pointer] != -1) {
            return memo[buy_i][pointer];
        }

        // recursive case: holding
        if (buy_i != m) {
            int sell_case = prices[pointer] - prices[buy_i] + dp(prices, m, pointer + 2, memo);
            int hold_case = dp(prices, buy_i, pointer + 1, memo);
            memo[buy_i][pointer] = (sell_case > hold_case) ? sell_case : hold_case;
            return memo[buy_i][pointer];
        } else {
            int buy_case = dp(prices, pointer, pointer + 1, memo);
            int wait_case = dp(prices, m, pointer + 1, memo);
            memo[buy_i][pointer] = (buy_case > wait_case) ? buy_case : wait_case;
            return memo[buy_i][pointer];
        }
    }
};
