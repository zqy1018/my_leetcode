class Solution:
    def arrangeCoins(self, n):
        """
        :type n: int
        :rtype: int
        """
        l, r = 0, 100000
        while r > l:
            mid = (r + l + 1) // 2
            if mid * (mid + 1) // 2 <= n:
                l = mid
            else:
                r = mid - 1
        return l