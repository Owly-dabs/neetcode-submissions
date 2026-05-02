class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ob = 1 # open brackets
        pl = n-1 # pairs left
        res = [["(",ob,pl]]
        out = []
        while res:
            r = res.pop()
            if r[1] > 0:
                nr = ["",0,0]
                nr[0] = r[0] + ')'
                nr[1] = r[1] - 1
                nr[2] = r[2]
                if len(nr[0]) == 2*n:
                    out.append(nr[0])
                else:
                    res.append(nr)

            if r[2] > 0:
                nr = ["",0,0]
                nr[0] = r[0] + '('
                nr[1] = r[1] + 1
                nr[2] = r[2] - 1
                if len(nr[0]) == 2*n:
                    out.append(nr[0])
                else:
                    res.append(nr)
        return out

