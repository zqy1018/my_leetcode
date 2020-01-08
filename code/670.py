class Solution:
    def maximumSwap(self, num: int) -> int:
        ss = list(str(num))
        l1 = len(ss)

        for i in range(l1):
            flag, targ = 0, -1
            for j in range(i + 1, l1):
                if int(ss[i]) < int(ss[j]):
                    flag = 1
                    if targ < 0:
                        targ = j
                    elif int(ss[j]) >= int(ss[targ]):
                        targ = j
            if flag:
                ss[i], ss[targ] = ss[targ], ss[i]
                return int("".join(ss))
        return num