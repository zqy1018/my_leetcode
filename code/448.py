class Solution:
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        len1 = len(nums)
        for i in range(0, len1):
            while nums[nums[i] - 1] != nums[i]:
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]
        
        lst = []
        for i in range(0, len(nums)):
            if nums[i] != i + 1:
                lst.append(i + 1)

        return lst