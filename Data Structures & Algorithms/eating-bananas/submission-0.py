class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def checkSpeed(k:int) -> bool:
            nh = 0
            for p in piles:
                nh += math.ceil(p/k )
            return nh <= h
        
        r = max(piles)
        l = 1

        while l<=r:
            k = (l+r)//2
            if checkSpeed(k):
                res = k
                r = k-1
            else:
                l = k + 1
        return res
