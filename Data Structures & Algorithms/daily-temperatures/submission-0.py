class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        if len(temperatures) == 1: return [0]

        res = [0 for _ in range(len(temperatures))]
        stack = [] # pair: [temp, ind]

        for i,t in enumerate(temperatures):
            while stack and stack[-1][0] < t:
                colder_temp, colder_ind = stack.pop()
                difference = i-colder_ind
                res[colder_ind] = difference
            
            stack.append((t,i))
        
        return res