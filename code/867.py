class Solution:
    def transpose(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        len1, len2 = len(A), len(A[0])
        ans = [[] for i in len2]
        for i in range(0, len2):
            for j in range(0, len1):
                ans[i].append(A[j][i])
        return ans
