class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1)>len(s2): return False
        fmap1 = [0 for _ in range(26)]
        fmap2 = [0 for _ in range(26)]
        l = 0
        r = l + len(s1)
        for i in range(r):
            fmap1[ord(s1[i]) - ord('a')] += 1
            fmap2[ord(s2[i]) - ord('a')] += 1

        while r<len(s2):
            print(fmap1, fmap2)
            if (fmap1 == fmap2): return True
            fmap2[ord(s2[l]) - ord('a')] -= 1
            fmap2[ord(s2[r]) - ord('a')] += 1
            l += 1
            r += 1
        if (fmap1 == fmap2): return True

        
        return False
        