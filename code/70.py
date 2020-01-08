class Solution:
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        f1, f2 = 0, 1
        while n:
            f2, f1 = f1 + f2, f2
            n -= 1
        return f2