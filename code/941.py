class Solution:
    def validMountainArray(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        len1 = len(A)
        if len1 < 3: return False
        cur = 1
        while cur < len1 and A[cur] > A[cur - 1]:
            cur += 1
        if cur == len1 or cur == 1: return False
        cur -= 1
        while cur < len1 - 1 and A[cur + 1] < A[cur]:
            cur += 1
        return cur == len1 - 1