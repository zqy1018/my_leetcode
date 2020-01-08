class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        l = len(num)
        for i in range(1, (2 * l) // 3):
            for j in range(0, i):
                if num[0] == "0" and j + 1 != 1:
                    break
                if num[j + 1] == "0" and i - j != 1:
                    continue
                lst1, lst2 = int(num[0: j + 1]), int(num[j + 1: i + 1])
                cur = i + 1
                flag = 1
                while cur < l:
                    nxt = lst1 + lst2
                    ll = len(str(nxt))
                    if ll + cur > l or int(num[cur: cur + ll]) != nxt:
                        flag = 0
                        break
                    cur += ll
                    lst1, lst2 = lst2, nxt

                if not flag:
                    continue
                else:
                    return True
        return False