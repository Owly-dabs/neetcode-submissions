class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # find the smallest number OR
        # find the starting index and create a new array
        # binary search on sorted array
        # [3, 5, 7, 9, 0, 2]
        # [1, 3, 5, 7, 9, 11, 13]
        # [9, 1, 4, 5, 8]
        # [4, 5, 1, 2, 3]
        # if higher_ind num > low_ind num && 
        #   target is in between nums
        #   binary search
        # else 
        l = 0
        r = len(nums) - 1
        i = (l+r)//2 # left preferring
        while nums[i] != target and r > l:
            if target > nums[i]:
                if nums[r] >= target or nums[r] < nums[i]:
                    # go right
                    l = i + 1
                else:
                    # go left
                    r = i
            else:
                if nums[l] <= target or nums[l] > nums[i]:
                    # go left
                    r = i
                else:
                    # go right
                    l = i + 1
            i = (l+r)//2 # left preferring
        if nums[i] == target: return i
        else: return -1