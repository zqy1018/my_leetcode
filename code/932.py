class Solution:
    def beautifulArray(self, N):
        """
        :type N: int
        :rtype: List[int]
        """
        lst, len1 = [1], 1
        while len1 < N:
            lst = [(i << 1) - 1 for i in lst] + [i << 1 for i in lst]
            len1 <<= 1
        return [i for i in lst if i <= N]
        