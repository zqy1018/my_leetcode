class Solution:
    def isMonotonic(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        len1 = len(A)
        if len1 == 1: return True
        cur = 0
        while cur < len1 - 1 and A[cur] <= A[cur + 1]:
            cur += 1
        if cur == len1 - 1: return True
        else:
            if A[0] != A[cur]: return False
            else:
                while cur < len1 - 1 and A[cur] >= A[cur + 1]:
                    cur += 1
                return cur == len1 - 1