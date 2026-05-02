class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // two greedy runs
        // first greedy run
        int currSum = 0;
        int tempSum = 0;
        bool filled = false;
        int maxElem = -1000;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]>maxElem) maxElem = nums[i];
            tempSum = tempSum + nums[i];
            if (tempSum>0) {
                currSum = tempSum + currSum;
                tempSum = 0;
                filled = true;
            }
        }
        if (!filled) {
            return maxElem;
        } else {
            tempSum = 0;
            for (int j=0; j<nums.size();j++) {
                tempSum = tempSum + nums[j];
                if (tempSum<0) {
                    currSum = currSum - tempSum;
                    tempSum = 0;
                }
            }
        }
        return currSum;

    }
};
