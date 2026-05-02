class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int m = nums.size();
        vector<vector<int>> buckets(m+1);
        unordered_map<int, int> map;
        vector<int> out;
        
        // build freq map
        for (int n:nums) {
            map[n]++;
        }

        int num;
        int f;
        // insert into buckets
        for (auto& p : map) {
            num = p.first;
            f = p.second;
            buckets[f].push_back(num);
        }

        int counter = 0;
        for (int freq = m; freq >= 0 && counter < k; freq--) {
            for (int num : buckets[freq]){
                out.push_back(num);
                counter++;
                if (counter == k) break;
            }
        }

        return out;
    }
};
