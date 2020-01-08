class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for i in nums[1: ]:
            nums[0] = nums[0] ^ i
        return nums[0]
        