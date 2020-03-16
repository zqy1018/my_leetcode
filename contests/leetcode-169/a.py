class Solution:
    def sumZero(self, n: int) -> List[int]:
        if n % 2 == 0:
            return [n - 1 - i - i for i in range(n)]
        else:
            return [(n >> 1) - i for i in range(n)]