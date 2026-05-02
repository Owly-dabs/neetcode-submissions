#include <vector>
class Solution {
public:
    int out;
    int m,n;
    int longestCommonSubsequence(string text1, string text2) {
        // base case: t == t
        // don't match: two recursive paths --> advance 1 or advance 2
        m = text1.size();
        n = text2.size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        out = recur(text1, text2, 0, 0, memo);
        return out;
    }

    int recur(
            const string& text1,
            const string& text2,
            int i,
            int j,
            vector<vector<int>>& memo){
        if (i == m || j == n) {
            return 0;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        if (text1[i] == text2[j]) {
            memo[i][j] = 1 + recur(text1, text2, i+1, j+1, memo);
            return memo[i][j];
        }
        else {
            int res1 = recur(text1, text2, i+1, j, memo);
            int res2 = recur(text1, text2, i, j+1, memo);
            if (res1 >= res2){
                memo[i][j] = res1;
                return memo[i][j];
            }
            else {
                memo[i][j] = res2;   
                return memo[i][j];
            }
        }
    }
};
