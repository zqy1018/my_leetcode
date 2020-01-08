class Solution:
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        def sqr(x):
            return x * x
        
        def getNum(x):
            res = 0
            while x:
                res += sqr(x % 10)
                x //= 10
            return res

        a = set()
        a.add(n)
        while n != 1 and n not in a:
            n = getNum(n)

        return n == 1     