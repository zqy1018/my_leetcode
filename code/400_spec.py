class Solution:
    def findNthDigit(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 10:
            return n
        i, p = 1, 9
        while True:
            n += p
            p = p * 10 + 9
            i += 1
            if n < i * p:
                return int(str((n + i - 1) // i)[(n + i - 1) % i])

        """ 核心思想是补余。
            寻找的顺序如下：
            1 2 3 4 ... 9
            -> 01 02 03 ... 99
            -> 001 002 003 ... 999
            所以n加的是p而不是i*p。只补上了前面的位数，与后面相齐。 """
