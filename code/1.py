class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        list = []
        length = len(nums)
        for i in range(0, length, 1):
            if (2 * nums[i] == target and nums.count(target - nums[i]) > 1) or (2 * nums[i] != target and nums.count(target - nums[i]) > 0):
                list.append(i)
                list.append(nums.index(target - nums[i], i + 1))
                break
        return list