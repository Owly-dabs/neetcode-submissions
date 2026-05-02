class Solution:
    def maxArea(self, heights: List[int]) -> int:
        l = 0
        r = len(heights)-1
        max_area = (r-l) * min(heights[l],heights[r])
        
        while l<r:
            if heights[l]<heights[r]:
                l += 1
            elif heights[r]<heights[l]:
                r -= 1
            else:
                l += 1
                r -= 1
            area = (r-l) * min(heights[l],heights[r])
            max_area = max(max_area, area)

        return max_area

             