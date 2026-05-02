class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        if (nums.size() == 1) {
            if (nums[0] == target) return 0;
            else return -1;
        }
        int ind = nums.size()/2;
        if (nums[ind] == target) return ind;
        else if (nums[ind] > target) {
            vector<int> subNums(nums.begin(), nums.begin() + ind);
            return search(subNums, target);
        } else {
            if (nums.begin() + ind > nums.end()) return -1;
            vector<int> subNums(nums.begin()+ ind + 1, nums.end());
            int result = search(subNums,target);
            if (result == -1) return -1;
            return result + ind + 1;
        }
    }
};
