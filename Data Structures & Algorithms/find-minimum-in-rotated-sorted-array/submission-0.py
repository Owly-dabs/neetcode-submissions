class Solution:
    def findMin(self, nums: List[int]) -> int:
        l = 0
        r = len(nums) - 1
        if nums[l] < nums[r]: return nums[l]
        while r-l>1:
            m = l + (r-l)//2
            if nums[m]>nums[l]:
                # discard  left
                l = m
            elif nums[m]<nums[l]:
                # discard right
                r = m
            else:
                print("ERROR")
        
        return nums[r]