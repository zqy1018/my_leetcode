class Solution:
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        sum, mini = 0, 3000000000
        for i in nums:
            sum += 1
            if i < mini:
                mini = i
        return sum - mini * len(nums)