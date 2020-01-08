class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        st = []
        for s in tokens:
            if s[-1].isdigit():
                st.append(int(s))
            else:
                op1, op2 = st[-2], st[-1]
                if s == "+":
                    res = op1 + op2
                if s == "-":
                    res = op1 - op2
                if s == "*":
                    res = op1 * op2
                if s == "/":
                    if op1 * op2 < 0:
                        res = -(abs(op1) // abs(op2))
                    else: res = op1 // op2
                st.pop()
                st.pop()
                st.append(res)
        return st[0]