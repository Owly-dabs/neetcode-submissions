class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        next_queue = [[]] # list of lists

        for n in nums:
            queue = next_queue
            next_queue = []
            #print(queue)
            while queue:
                arr1 = queue.pop()
                arr2 = arr1.copy()
                arr1.append(n)
                if arr1 not in next_queue:
                    next_queue.append(arr1)
                if arr2 not in next_queue:
                    next_queue.append(arr2)
        
        return next_queue