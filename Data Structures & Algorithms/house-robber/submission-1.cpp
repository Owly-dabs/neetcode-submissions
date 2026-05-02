class Solution {
public:
    int rob(vector<int>& nums) {
        // while you can technically skip over 3 houses,
        // it does not make sense.
        // you either skip one or two
        unordered_map<int,int> memo;
        return max(dfs(nums,0,memo), dfs(nums,1,memo));
    }
private:
    int dfs(vector<int>& nums, int ind, unordered_map<int,int>& memo){
        if (memo.count(ind)) return memo[ind];
        if (ind>=nums.size()) return 0;

        memo[ind] = nums[ind] + max(dfs(nums,ind+2,memo),dfs(nums,ind+3,memo));
        return memo[ind];       
    }
};
