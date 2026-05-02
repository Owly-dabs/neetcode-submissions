class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        int remainder;

        // for each integer
        for (int i = 0; i < nums.size(); i++) {

        // check if num[i] is in hashmap. If yes, return (index of remainder,i)
            if (map.count(nums[i])) {
                vector<int> out = {map[nums[i]], i};
                return out;
            }
        
            else {
            // calculate the remainder = target - nums[i]
                remainder = target - nums[i];
            // enter (remainder,i) into a hashmap<int,int> 
                map[remainder] = i;
            }
        
        }
    }
};
