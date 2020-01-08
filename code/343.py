class Solution:
    def integerBreak(self, n: int) -> int:
        if n == 2: return 1
        if n == 3: return 2
        ans = 0
        for i in range(0, n + 1, 2):
            if (n - i) % 3 == 0:
                ans = max(ans, (2 ** (i // 2)) * (3 ** ((n - i) // 3)))
        return ans
