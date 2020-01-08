class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        n = ((0xAAAAAAAA & n) >> 1) + (n & 0x55555555)
        n = ((0xCCCCCCCC & n) >> 2) + (n & 0x33333333)
        n = ((0xF0F0F0F0 & n) >> 4) + (n & 0x0F0F0F0F)
        n = ((0xFF00FF00 & n) >> 8) + (n & 0x00FF00FF)
        n = ((0xFFFF0000 & n) >> 16) + (n & 0x0000FFFF)
        return n
        