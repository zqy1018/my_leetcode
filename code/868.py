class Solution:
    def binaryGap(self, N):
        """
        :type N: int
        :rtype: int
        """
        j = 1
        fst, ans = 0, 0
        while j <= N and (j & N) == 0:
            fst += 1
            j <<= 1
        while j <= N:
            t, cur = j << 1, fst + 1
            while t <= N and (t & N) == 0:
                cur += 1
                t <<= 1
            if t > N:
                break
            ans = max(ans, cur - fst)
            j, fst = t, cur
        return ans