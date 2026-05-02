class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        bool containsZero = false;
        bool containsMoreThanOneZero = false;
        vector<int> out;

        // get product of all non-zero numbers
        for (int n : nums) {
            if (n==0) {
                if (!containsZero) {
                    containsZero = true;
                    continue;
                }
                else {
                    containsMoreThanOneZero = true;
                    break;
                }
            } 
            prod = prod * n;
        }

        // populate the out vector
        if (containsMoreThanOneZero) {
            for (int i = 0; i < nums.size(); i++) {
                out.push_back(0);
            }
        }
        else if (containsZero) {
            for (int n : nums) {
                if (n == 0) {
                    out.push_back(prod);
                } else {
                    out.push_back(0);
                }
            }
        } else {
            for (int n : nums) {
                out.push_back(prod/n);
            }
        }

        return out;
    }
};
