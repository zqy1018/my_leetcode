class Solution:
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        z, ans = x ^ y, 0
        while z:
            ans += 1
            z -= z & (-z)
        return ans