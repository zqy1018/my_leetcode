class Solution:
    def checkPerfectNumber(self, num):
        """
        :type num: int
        :rtype: bool
        """
        i, sum = 1, -num
        while i * i < num:
            if num % i == 0:
                sum += i + num // i
            i += 1
        if i * i == num:
            sum += i
        return num == sum