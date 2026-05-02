class Solution:
    def sumOfSquares(self, n: int) -> int:
        output = 0

        while n:
            digit = (n%10)**2
            output += digit
            n = n//10
        return output
        
    def isHappy(self, n: int) -> bool:
        visit =set()
        while n not in visit:
            visit.add(n)
            n = self.sumOfSquares(n)
            if (n == 1): return True
        return False