class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if nums == []:
            return 1
        len1 = len(nums)
        for i in range(0, len1):
            while True:
                if nums[i] > len1 or nums[i] <= 0 or nums[nums[i] - 1] == nums[i] or i == nums[i] - 1:
                    break
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]
        i = 0
        while i < len1:
            if nums[i] != i + 1:
                break
            i += 1
        return i + 1
            