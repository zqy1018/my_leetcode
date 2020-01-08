class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        ans = 1
        for i in range(n + 1, 2 * n + 1):
            ans *= i
        for i in range(1, n + 2):
            ans //= i
        return ans
        