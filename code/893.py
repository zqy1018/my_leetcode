class Solution:
    def numSpecialEquivGroups(self, A):
        """
        :type A: List[str]
        :rtype: int
        """
        if len(A[0]) == 1:
            A.sort()
        else:
            len1 = len(A)
            for i in range(0, len1):
                ls = list(A[i])
                ls1, ls2 = ls[0: : 2], ls[1: : 2]
                ls1.sort()
                ls2.sort()
                A[i] = "".join(ls1) + "".join(ls2)
        return len(set(A))