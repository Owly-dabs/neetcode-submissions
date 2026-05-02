class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // bottom-up DP
        // From the last index
        // Calculate upwards until reaching index 0
        // Compare min cost of index 0 and 1 and return smaller one
        vector<int> memo (cost.size(),0);
        memo[0] = cost.back();
        memo[1] = cost[cost.size()-2];
        for (int i=2; i<cost.size(); i++) {
            int ind = cost.size() - 1 - i;
            memo[i] = cost[ind] +  min(memo[i-1], memo[i-2]);
        }

        return min(memo[cost.size()-1], memo[cost.size()-2]);
    }
};
