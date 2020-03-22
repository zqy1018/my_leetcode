class Solution:
    def getKth(self, lo: int, hi: int, k: int) -> int:
        def get(x):
            res = 0
            while x != 1:
                if x % 2 == 1: x = 3 * x + 1
                else: x = x // 2
                res += 1
            return res

        lis = []

        for i in range(lo, hi + 1):
            lis.append((get(i), i))
        lis.sort()
        return lis[k - 1][1]
        
a = Solution()
print(a.getKth(10, 20, 5))