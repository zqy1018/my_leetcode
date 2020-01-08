class Solution:
    def selfDividingNumbers(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """
        ans = []
        for i in range(left, right + 1):
            x = i
            while x:
                if x % 10 == 0 or i % (x % 10) != 0:
                    break
                x //= 10
            if x == 0:
                ans.append(i)
        return ans