class Solution:
    
    def numDecodings(self, s: str) -> int:
        memo = {}
        def dp(ss:str) -> int:
            # if stored in memo
            if memo.get(ss):
                return memo[ss]
            # base case
            if ss == "":
                return 1
            if ss[0] == "0":
                return 0
            if len(ss) == 1:
                return 1
            else:
                # Recursive case for 1 and 2 (and not last digit)
                if ss[0] == "1" or ss[0] == '2':
                    if ss[0:2] == '10' or ss[0:2] == '20':
                        if len(ss) == 2:
                            memo[ss] = 1
                            return memo[ss]
                        else:
                            memo[ss] = dp(ss[2:])
                            return memo[ss]
                    elif int(ss[0:2]) <= 26:
                        memo[ss] = dp(ss[1:]) + dp(ss[2:])
                        return memo[ss]
                    else: # 27-29
                        memo[ss] = dp(ss[1:]) 
                        return memo[ss]

                # Recursive case for 3-9
                else:
                    memo[ss[1:]] = dp(ss[1:])
                    return memo[ss[1:]]
        return dp(s)