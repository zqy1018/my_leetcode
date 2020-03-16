class Solution:
    def strobogrammaticInRange(self, low: str, high: str) -> int:
        a, b = int(low), int(high)
        l1, l2 = len(low), len(high)
        