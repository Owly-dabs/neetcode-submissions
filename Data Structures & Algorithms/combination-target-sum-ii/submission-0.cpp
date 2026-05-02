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
        if (sum(curr) == t) {
            out.push_back(curr);
        }
        else if (sum(curr) < t && ind < nums.size()) {
            unordered_set<int> check;
            for (int i=ind; i<nums.size(); i++) {
                if (check.count(nums[i])) continue;
                vector<int> newV = curr;
                newV.push_back(nums[i]);
                dfs(nums, t, i+1, newV);
                check.insert(nums[i]);
            }
        }
        return;
    }
    int sum(vector<int> nums) {
        int s = 0;
        for (int n:nums) {
            s = s+n;
        }
        return s;
    }
};
