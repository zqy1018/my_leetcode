class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mini, ans, sums = 0, -3000000000, 0
        for i in nums:
            sums += i
            ans = max(ans, sums - mini)
            if sums < mini: mini = sums
        return ans