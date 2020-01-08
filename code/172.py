class Solution:
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        cnt = 0
        i = 5
        while i <= n:
            cnt += n // i
            i *= 5
        return cnt