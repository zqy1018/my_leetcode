class Solution:
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        z = 1
        while (z << 1) <= num:
            z <<= 1
        return (-num - 1) & ((z << 1) - 1)