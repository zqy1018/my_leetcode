class Solution:
    def largestPalindrome(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 1:
            return 9
        p = 1
        for i in range(0, n):
            p *= 10
        for a in range(2, p):
            u = p - a
            l = int(str(u)[: : -1])
            if a ** 2 - 4 * l >= 0:
                i = (a + (a ** 2 - 4 * l) ** 0.5) / 2
                if i == int(i):
                    return (u * p + l) % 1337