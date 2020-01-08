class Solution:
    def smallestRangeI(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        mini, maxi = 3000000000, -1
        for i in A:
            if i > maxi:
                maxi = i
            if i < mini:
                mini = i
        return max(0, maxi - K - mini - K)