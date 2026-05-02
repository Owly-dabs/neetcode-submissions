class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        l = 0
        freqs = [0 for i in range(26)]
        max_length = 0

        for r in range(len(s)):
            freqs[ord(s[r]) - ord('A')] += 1

            length = r-l+1
            if length-max(freqs) <= k: 
                max_length = max(max_length, length)
                continue
            else:
                while length-max(freqs) > k:
                    freqs[ord(s[l]) - ord('A')] -= 1
                    l += 1
                    length = r-l+1
            
        return max_length