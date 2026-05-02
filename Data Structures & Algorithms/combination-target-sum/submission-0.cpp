class Solution {
public:
    vector<vector<int>> out;
    //vector<int> memo(target,)
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        dfs(nums, target, 0, 0, {});
        return out;
    }
private: 
    void dfs(vector<int>& nums, int target, int i, int sum, vector<int> curr) {
        if (sum==target) {
            out.push_back(curr);
            return;
        }
        if (sum>target || i>=nums.size()) return;

        curr.push_back(nums[i]);
        dfs(nums, target, i, sum+nums[i], curr);
        curr.pop_back();
        dfs(nums,target, i+1, sum, curr);
    }
};
