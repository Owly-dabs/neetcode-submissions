class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int n : nums) {
            if (map.count(n)) {
                return true;
            } else {
                map[n] = 1;
            }
        }
        return false;
    }
};
