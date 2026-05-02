class Solution {
public:
    vector<vector<int>> memo;
    int rob(vector<int>& nums) {
        if (nums.size()==1) return nums[0];
        memo = vector<vector<int>>(nums.size(),vector<int>(2,0));
        return dfs(nums, 0, 0);
    }
private: 
    int dfs(vector<int>& nums, int i, int flag){
        if (i<nums.size() && memo[i][flag]!=0) return memo[i][flag];
        if (flag==0) {
            if (i>=nums.size()-1) return 0;
        } else {
            if (i>=nums.size()) return 0;
        }
        if (i==0) {
            return max(nums[i] + dfs(nums, i+2, 0),
                 dfs(nums, i+1, 1));
        }
        memo[i][flag] = max(nums[i] + dfs(nums,i+2,flag),
                    dfs(nums,i+1,flag));
        return memo[i][flag];
    }
};
