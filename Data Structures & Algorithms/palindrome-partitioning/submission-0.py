class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def isPalindrome(st: str) -> bool:
            return st == st[::-1]
        
        res = []
        n = len(s)
        def backtrack(i: int, j: int, track: List[str]):
            print(j,i)
            if j == n: 
                res.append(track)
                return
            if i == n:
                return
            i += 1
            if isPalindrome(s[j:i]):
                track.append(s[j:i])
                backtrack(i, i, track.copy())
                track.pop()
                backtrack(i, j, track.copy())
            else:
                backtrack(i, j, track.copy())
            
        backtrack(0, 0, [])
        return res
