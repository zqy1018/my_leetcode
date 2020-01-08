class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x < 0:
            res = (-int(str(-x)[-1: : -1]))
        else:
            res = (int(str(x)[-1:: -1]))
        if res < -2147483648 or res > 2147483647:
            return 0
        else:
            return res
