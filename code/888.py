class Solution:
    def fairCandySwap(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        q, p = sum(A), sum(B)
        s =  (p + q) >> 1
        set1 = set(B)
        for i in A:
            if s + i - q in set1:
                return [i, s + i - q]