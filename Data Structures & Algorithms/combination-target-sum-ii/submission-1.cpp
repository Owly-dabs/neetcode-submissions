class Solution {
public:
    vector<vector<int>> out;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, {});
        return out;
    }
private:
    void dfs(vector<int>& nums, int t, int ind, vector<int> curr) {
        int sum = 0;
        for (int n:curr) sum += n;
        if (sum==t) {
            out.push_back(curr);
            return;
        }
        if (sum>t || ind >= nums.size()) return;
        vector<int> newV = curr;
        newV.push_back(nums[ind]);
        dfs(nums, t, ind+1, newV);
        int i = ind;
        while (nums[i] == nums[ind]) i++;
        dfs(nums, t, i, curr);
        return;
    }
};
