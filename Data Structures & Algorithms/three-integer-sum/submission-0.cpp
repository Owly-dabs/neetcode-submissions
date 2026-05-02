class Solution {
public:
    string encode(pair<int,int> p) {
        return to_string(p.first)+","+to_string(p.second);
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> out;
        unordered_map<int,int> hash;
        unordered_set<string> checked;
        sort(nums.begin(),nums.end());
        for (int i=0;i<nums.size();i++){
            hash[nums[i]] = i;
        }
        for (int i=0;i<nums.size();i++) {
            for (int j=i+1;j<nums.size();j++) {
                if (!checked.count(encode({nums[i],nums[j]}))){
                    int n = 0-nums[i]-nums[j];
                    if (n>=nums[j] && hash[n] && hash[n]!=i && hash[n]!=j) out.push_back({nums[i],nums[j],n});
                    checked.insert(encode({nums[i],nums[j]}));
                }
                
            }
        }
        return out;
    }
};
