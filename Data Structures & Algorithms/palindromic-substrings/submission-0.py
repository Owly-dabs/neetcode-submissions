class Solution:
    def countSubstrings(self, s: str) -> int:
        memo = {}
        res = 0
        def dp(l:int, r:int) -> int:
            if memo.get((l,r)):
                return memo[(l,r)]
            if l<0 or r >= len(s):
                memo[(l,r)] = 0
                return memo[(l,r)]
            if s[l] != s[r]:
                memo[(l,r)] = 0
                return memo[(l,r)]
            else:
                memo[(l,r)] = 1 + dp(l-1,r+1)
                return memo[(l,r)]

        for i in range(len(s)):
            res += dp(i,i)
            if i <= len(s) - 2:
                res += dp(i, i+1)
        return res