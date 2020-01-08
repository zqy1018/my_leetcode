class Solution:
    def fib(self, N: int) -> int:
        if N == 0: return 0
        if N == 1: return 1
        f1, f2 = 0, 1
        for i in range(1, N):
            f1, f2 = f2, f1 + f2
        return f2