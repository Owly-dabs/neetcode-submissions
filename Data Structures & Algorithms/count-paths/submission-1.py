class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        if m == 1 and n == 1: return 1
        memo = {}
        def dp(i: int, j: int) -> int:
            if memo.get((i,j)):
                return memo[(i,j)]
            elif m-i == 1 and n-j == 0:
                memo[(i,j)] = 1
                return 1
            elif n-j == 1 and m-i == 0:
                memo[(i,j)] = 1
                return 1
            elif i>m or j>n:
                memo[(i,j)] = 0
                return 0
            else:
                memo[(i,j)] = dp(i+1,j) + dp(i,j+1)
                return memo[(i,j)]
        return dp(1,1)