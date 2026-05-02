class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        memo = {}
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 2:
                    memo[(i,j)] = self.check_adjacents(grid, i, j)
                    if memo[(i,j)] == []:
                        del memo[(i,j)]

        time = 0

        # For each 2
            # Check if there are adjacent 1s
            # If None: return -1 if there are remaining ones else return res
        while len(memo) > 0:
            new_adjacents = set()
            for pos, adjacents in memo.items():
                for a_pos in adjacents:
                    new_adjacents.add(a_pos)
                    grid[a_pos[0]][a_pos[1]] = 2
            
            memo = {}
            # populate memo again
            for pos in list(new_adjacents):
                memo[pos] = self.check_adjacents(grid, pos[0], pos[1])
                if memo[pos] == []:
                    del memo[pos]
            
            time += 1

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    return -1
        
        return time
    
    def check_adjacents(self, grid, i ,j) -> list[tuple[int,int]]:
        """
        Return list of coordinates for adjacent 1s
        """
        adjacents = [
            (i+1, j),
            (i-1, j),
            (i, j+1),
            (i, j-1)
        ]

        res = []

        for pos in adjacents:
            if pos[0] < len(grid) and pos[0] >= 0:
                if pos[1] < len(grid[0]) and pos[1] >= 0:
                    if grid[pos[0]][pos[1]] == 1:
                        res.append(pos)
        
        return res