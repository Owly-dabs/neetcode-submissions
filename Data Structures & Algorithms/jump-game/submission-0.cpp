class Solution {
public:
    bool canJump(vector<int>& nums) {
        // Always start at first one
        // DP + top down recursion?
        unordered_map<int,bool> memo;
        return dfs(nums,0,memo);
    }
private:
    bool dfs(vector<int>& nums, int i, unordered_map<int,bool>& memo) {
        if (memo.count(i)) return memo[i];
        if (i+nums[i]>=nums.size()-1) return true;

        for(int j=1; j<=nums[i]; j++) {
            if (dfs(nums, i+j, memo)){
                memo[i+j] = true;
                return true;
            }
        }
        memo[i] = false;
        return false;
    }
};
