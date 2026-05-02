class Solution:
    def trap(self, height: List[int]) -> int:
        l=0
        r=len(height) - 1
        maxL = height[l]
        maxR = height[r]
        water = 0
        # let p1 be the first non-zero number
        while l<r:
            minLR = min(maxL,maxR)
            if maxL<=maxR:
                l += 1
                if minLR > height[l]:
                    water += minLR - height[l]
                if height[l] > maxL:
                    maxL = height[l]
            else:
                r -= 1
                if minLR > height[r]:
                    water += minLR - height[r]
                if height[r] > maxR:
                    maxR = height[r]
        
        return water
