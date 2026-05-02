class Solution {
public:
    vector<vector<int>> out;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> tracker(nums.size(),false);
        vector<int> curr = {};
        dfs(nums,curr,tracker);
        return out;
    }
    void dfs(vector<int>& nums, vector<int>& curr, vector<bool>& tracker){
        if (curr.size() == nums.size()) {
            out.push_back(curr);
            return;
        }
        for (int i=0; i<tracker.size(); i++) {
            if (!tracker[i]) {
                vector<int> copy = curr;
                copy.push_back(nums[i]);
                vector<bool> copy_tracker = tracker;
                copy_tracker[i] = true;
                dfs(nums,copy,copy_tracker);
            }
        }
        return;
    }
};
