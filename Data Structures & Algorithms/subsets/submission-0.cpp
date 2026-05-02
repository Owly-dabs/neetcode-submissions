class Solution {

public:

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> out;
        out.push_back({});

        if (nums.empty());
        else if (nums.size() == 1) {
            out.push_back(nums);
        } else {
            for (int n:nums) {
                vector<vector<int>> snapshot = out;
                for (vector<int> v:snapshot) {
                    vector<int> newVec = v;
                    newVec.push_back(n);
                    out.push_back(newVec);
                }
            }
        }
        return out;
    }
};
