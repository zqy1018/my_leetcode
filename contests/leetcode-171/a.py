class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        for i in range(1, n):
            s1, s2 = str(i), str(n - i)
            if '0' in s1 or '0' in s2:
                continue
            return [i, n - i]
        return []