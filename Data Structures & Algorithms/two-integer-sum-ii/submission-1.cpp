class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // init pointers
        int i = 0;
        int j = numbers.size() - 1;

        while (numbers[i] + numbers[j] != target) {
            if (numbers[i] + numbers[j] > target) {
                j--;
                continue;
            }
            if (numbers[i] + numbers[j] < target) {
                i++;
                continue;
            }
        }

        vector<int> out = {i+1, j+1};
        return out;
    }
};
