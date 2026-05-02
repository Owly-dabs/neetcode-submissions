class Solution:
    def minWindow(self, s: str, t: str) -> str:
        l, r = 0, 0
        res = s
        found = False
        ht = {}
        hs = {}
        for c in t:
            ht[c] = 1 + ht.get(c, 0)

        have = 0
        need = len(ht)
        
        for r,c in enumerate(s):
            if c in ht.keys():
                hs[c] = 1 + hs.get(c,0)
            
            if c in ht and hs[c] == ht[c]:
                have += 1
            
            while have == need:
                found = True

                if r-l+1 < len(res):
                    res = s[l:r+1] # r+1 is not inclusive

                if s[l] in ht.keys():
                    hs[s[l]] -= 1
                    if hs[s[l]] < ht[s[l]]:
                        have -= 1

                l += 1
                
            print("hs:", hs)
            print("res:", res)


        if not found:
            return ""
        else:
            return res