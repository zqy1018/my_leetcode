class Solution:
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        if n == 0:
            return [0]
        elif n == 1:
            return [0, 1]
        else:
            ans, j = [0, 1, 3, 2], 4
            while n > 2:
                i = 0
                while i < (j << 1):
                    a, b = ans[i], ans[i + 1]
                    ans[i], ans[i + 1] = (a | 1), (b | 1)
                    ans[i: i] = [a]
                    ans[i + 1: i + 1] = [b]
                    i += 4
                n -= 1
                j <<= 1
            return ans