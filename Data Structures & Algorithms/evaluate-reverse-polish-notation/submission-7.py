class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = [] # integers
        for t in tokens:
            if t.isdigit() or len(t)>1:
                stack.append(int(t))
            else:
                if t == "+":
                    res = stack.pop() + stack.pop()
                elif t == "-":
                    res = -stack.pop()+stack.pop()
                elif t == "*":
                    res = stack.pop()*stack.pop()
                elif t =="/":
                    temp = stack.pop()
                    res = stack.pop()/temp
                    if res<0 and res%1!=0: res=int(res//1+1)
                    else: res = int(res//1)
                
                stack.append(res)
        return stack.pop()