class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        squares = [set() for _ in range(9)]
        for i in range(9):
            for j in range(9):
                # Check if digit
                if board[i][j].isdigit():
                    num = int(board[i][j])
                    # Yes -> check row
                    if num in rows[i]:
                        return False
                    else:
                        rows[i].add(num)
                    # Yes -> check col
                    if num in cols[j]:
                        return False
                    else:
                        cols[j].add(num)
                    # yes -> check square
                    square_index = (i//3)*3 + (j//3)
                    if num in squares[square_index]:
                        return False
                    else:
                        squares[square_index].add(num)
        
        return True