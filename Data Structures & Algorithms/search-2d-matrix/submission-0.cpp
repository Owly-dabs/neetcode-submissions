class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Iterative approach within a vector
        int a = 0;
        int b = matrix.size() - 1;
        while (a <= b) {
            int c = a + ((b - a) / 2);
            vector<int> v = matrix[c];
            if (v.front() <= target && v.back() >= target) {
                int l = 0;
                int r = v.size() - 1;
                int m;
                while (l <= r) {
                    m = l + ((r - l) / 2);
                    if (v[m] == target) return true;
                    else if (v[m] > target){
                        r = m - 1;
                    }
                    else {
                        l = m + 1;
                    }
                }
                return false;
            }
            else if (v.front() > target) {
                b = c - 1;
            }
            else if (v.back() < target) {
                a = c + 1;
            }
        }
        return false;
        
    }
};
