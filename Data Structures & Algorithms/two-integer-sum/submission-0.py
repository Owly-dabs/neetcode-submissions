class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash_table = {}
        for i,n in enumerate(nums):
            # if number in hash table, return indices
            if n in hash_table: return [hash_table.get(n), i]
            hash_table[target-n] = i