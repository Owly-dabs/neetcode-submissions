class Solution:
    def search(self, nums: List[int], target: int) -> int:
        j = len(nums)
        i = 0
        k=(i+j)//2
        if nums[i] == target: return i
        while i!=k:
            n = nums[k]
            if n == target: return k
            if target>n: 
                i = k
            else: j = k
            k=(i+j)//2
        return -1