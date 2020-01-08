class Solution:
    def minIncrementForUnique(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        if A == []: return 0
        A.sort()
        lst, ans, len1 = 0, 0, len(A)
        for i in range(1, len1):
            if A[i] != A[lst]:
                cur = min(A[i] - A[lst], i - lst - 1)
                ans += (2 * (i - lst) - 1 - cur) * cur // 2
                if cur == i - lst - 1:
                    lst = i
                else:
                    lst += cur
                    A[lst] += cur
        cur = len1 - lst
        ans += (len1 - lst - 1) * (len1 - lst) // 2
        return ans