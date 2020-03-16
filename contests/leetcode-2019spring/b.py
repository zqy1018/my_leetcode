class Solution:
    def minimizeError(self, prices: List[str], target: int) -> str:
        len1 = len(prices)
        lis = [2000000000] * (target + 1)
        able = [0] * (target + 1)
        able[target] = 1
        lis[target] = 0
        set1 = {target}
        set2 = set()
        for i in range(len1):
            f = float(prices[i])
            lb, ub = math.floor(f), math.ceil(f)
            if lb != ub:
                lc = int(prices[i][-3: ])
                uc = 1000 - lc
            else:
                lc, uc = 0, 0
            for j in set1:
                if j - ub >= 0:
                    if able[j - ub] == i + 2:
                        lis[j - ub] = min(lis[j - ub], lis[j] + uc)
                    else:
                        lis[j - ub] = lis[j] + uc
                        able[j - ub] = i + 2
                        set2.add(j - ub)
                if j - lb >= 0:
                    if able[j - lb] == i + 2:
                        lis[j - lb] = min(lis[j - lb], lis[j] + lc)
                    else:
                        lis[j - lb] = lis[j] + lc
                        able[j - lb] = i + 2
                        set2.add(j - lb)
            if lb == 0:
                lis[target] += lc
                able[target] = i + 2
                set2.add(target)
            elif target - lb >= 0 and able[target] == i + 1:
                if able[target - lb] != i + 2:
                    lis[target - lb] = lis[target] + lc
                    able[target - lb] = i + 2
                else:
                    lis[target - lb] = min(lis[target - lb], lis[target] + lc)
        if lis[0] < 2000000000 and able[0] == len1 + 1:
            ss = lis[0] / 1000
            return ("%.3lf" % (ss))
        else:
            return "-1"


