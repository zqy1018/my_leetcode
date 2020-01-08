class Solution:
    def judgeSquareSum(self, c):
        """
        :type c: int
        :rtype: bool
        """
        i, j = 0, int(c ** 0.5) + 1
        while i <= j:
            res = i * i + j * j
            if res == c:
                return True
            elif res < c:
                i += 1
            elif res > c:
                j -= 1
        return False