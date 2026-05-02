class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m = len(board)
        n = len(board[0])
        hset = set()
        def dfs(i:int, j:int, c:int) -> bool:
            if board[i][j] == word[c]:
                # Base case
                if c == len(word)-1: return True

                # Recursive case
                hset.add((i,j)) #(0,2),(1,2)
                c = c + 1
                if i+1<m and (i+1,j) not in hset:
                    if dfs(i+1,j,c):
                        return True
                if i-1>=0 and (i-1,j) not in hset:
                    if dfs(i-1,j,c):
                        return True
                if j+1<n and (i,j+1) not in hset:
                    if dfs(i,j+1,c):
                        return True
                if j-1>=0 and (i,j-1) not in hset:
                    if dfs(i,j-1,c):
                        return True
                
                hset.remove((i,j))
                return False
            else:
                return False

        for i in range(m):
            for j in range(n):
                if dfs(i,j,0): return True
        
        return False
        