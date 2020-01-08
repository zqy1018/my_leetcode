class Solution:
    def minDeletionSize(self, A):
        """
        :type A: List[str]
        :rtype: int
        """
        len1 = len(A)
        if len1 <= 1: return 0
        len2, ans = len(A[0]), 0
        for i in range(0, len2):
            flag = 1
            for j in range(1, len1):
                if A[j][i] <= A[j - 1][i]:
                    flag = 0
                    break
            if not flag: ans += 1
        return ans
