class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ltr;
        vector<int> rtl;

        ltr.push_back(nums[0]);
        rtl.push_back(nums[nums.size()-1]);
        for (int i = 1; i < nums.size(); i++) {
            ltr.push_back(ltr.back() * nums[i]);
            rtl.push_back(rtl.back() * nums[nums.size()-1-i]);
        }

        // populate out
        vector<int> out;
        for (int i = 0; i < nums.size(); i++) {
            if (i==0) out.push_back(rtl[nums.size()-2]);
            else if (i==nums.size()-1) out.push_back(ltr[nums.size()-2]);
            else out.push_back(ltr[i-1] * rtl[nums.size() - 2 - i]);
        }
        return out;
    }
};
