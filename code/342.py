class Solution:
    def isPowerOfFour(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num == 1: return True
        if num <= 0 or (num & (-num)) != num: return False
        from math import sqrt
        k = sqrt(num)
        return abs(k - round(k)) < 1e-2