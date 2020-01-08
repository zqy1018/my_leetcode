class Solution:
    def countOfAtoms(self, formula: str) -> str:
        formula = "(" + formula + ")"
        l = len(formula)

        def mmerge(dst, src, xs):
            for k, v in src.items():
                t = dst.get(k, 0)
                dst[k] = v * xs + t

        def aux(st):
            nonlocal formula, l
            res = {}
            st += 1
            while st < l and formula[st] != ')':
                if formula[st].isupper():
                    j = st + 1
                    while j < l and formula[j].islower():
                        j += 1
                    rp = j
                    while j < l and formula[j].isdigit():
                        j += 1
                    x = 1 if j == rp else int(formula[rp: j])
                    x += res.get(formula[st: rp], 0)
                    res[formula[st: rp]] = x
                    st = j
                elif formula[st] == '(':
                    endp, rres = aux(st)
                    j = endp + 1
                    while j < l and formula[j].isdigit():
                        j += 1
                    xs = 1 if j == endp + 1 else int(formula[endp + 1: j])
                    mmerge(res, rres, xs)
                    st = j
            return st, res

        _, ans = aux(0)
        lis = sorted(ans.keys())
        aans = []
        for s in lis:
            aans.append(s)
            t = ans[s]
            if t > 1:
                aans.append(str(t))

        return "".join(aans)