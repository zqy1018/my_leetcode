class Solution(object):
    def consecutiveNumbersSum(self, N):
        """
        :type N: int
        :rtype: int
        """
        i, ans = 1, 0
        N *= 2
        while i * i <= N:
            if N % i == 0:
                if (i + N // i - 1) & 1 == 0:
                    j = (i + N // i - 1) // 2
                    if i > j:
                        ans += 1
                    if N // i > j:
                        ans += 1
            i += 1
        return ans