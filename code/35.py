class Solution:
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        len1 = len(nums)
        if len1 == 0: return 0
        l2, r2 = 0, len1
        while l2 < r2:
            mid = (l2 + r2) >> 1
            if nums[mid] > target:
                r2 = mid
            else:
                l2 = mid + 1
        if l2 == 0: return 0
        else:
            if nums[l2 - 1] == target:
                return l2 - 1
            else:
                return l2