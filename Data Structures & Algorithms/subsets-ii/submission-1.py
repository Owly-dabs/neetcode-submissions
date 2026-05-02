class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()

        def backtrack(i: int, subset: List[int]):
            if i == len(nums):
                res.append(subset[::])
                return
            
            # case where new number is added
            subset.append(nums[i])
            backtrack(i+1, subset)
            subset.pop()

            # case where new number is not added
            while i<len(nums) - 1 and nums[i] == nums[i+1]:
                i += 1
            backtrack(i+1, subset)

        backtrack(0, [])
        return res