class Solution:
    def splitIntoFibonacci(self, S: str) -> List[int]:
        l = len(S)
        lst = []
        for i in range(1, (2 * l) // 3):
            for j in range(0, (i + 1) // 2):
                if S[0] == "0" and j + 1 != 1:
                    break
                if S[j + 1] == "0" and i - j != 1:
                    continue
                
                lst.append(int(S[0: j + 1]))
                lst.append(int(S[j + 1: i + 1]))

                cur = i + 1
                flag = 1
                while cur < l:
                    nxt = lst[-1] + lst[-2]
                    ll = len(str(nxt))
                    if ll + cur > l or int(S[cur: cur + ll]) != nxt or nxt >= 2147483648:
                        flag = 0
                        break
                    lst.append(nxt)
                    cur += ll

                if not flag:
                    lst.clear()
                    continue
                else:
                    return lst
        return lst