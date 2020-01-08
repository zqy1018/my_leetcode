class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        lst1 = list(map(lambda x: int(x), version1.split(".")))
        lst2 = list(map(lambda x: int(x), version2.split(".")))

        l1, l2 = len(lst1), len(lst2)
        l = max(l1, l2)
        for i in range(l):
            c1, c2 = 0, 0
            if i < l1: c1 = lst1[i]
            if i < l2: c2 = lst2[i]
            if c1 != c2: return 1 if c1 > c2 else -1
        return 0
