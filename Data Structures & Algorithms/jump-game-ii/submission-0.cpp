class Solution {
public:
    vector<int> memo;
    int jump(vector<int>& nums) {
        memo.resize(nums.size(), -1);
        return dfs(nums, 0);
    }
private:
    int dfs(vector<int>& nums, int ind) {
        if (memo[ind]!=-1) return memo[ind];
        if (ind >= nums.size()-1) return 0;
        if (nums[ind]==0) return 1001;
        int min_jumps=1000;
        for (int i=1; i<=nums[ind]; i++){
            int j = dfs(nums,ind+i);
            min_jumps = min(j, min_jumps);
            
        } 
        cout << "Min jumps at ind "<< ind <<" is "<< 1+min_jumps<<endl;
        memo[ind] = 1 + min_jumps;
        return memo[ind];
    }
};
