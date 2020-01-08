class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0: return False
        if x == 0: return True
        t = 1
        while t * 10 <= x:
            t *= 10
        while x:
            m, n = x // t, x % 10
            if m != n: return False
            x -= m * t
            x //= 10
            t //= 100
        return True