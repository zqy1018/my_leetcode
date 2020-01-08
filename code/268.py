class Solution:
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        p, n = 0, len(nums) + 1
        for i in nums:
            p -= i
        return p + n * (n + 1) // 2