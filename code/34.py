class Solution:
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        len1 = len(nums)
        if len1 == 0: return [-1, -1] 
        l1, l2, r1, r2 = 0, 0, len1, len1
        while l1 < r1:
            mid = (l1 + r1) >> 1
            if nums[mid] >= target:
                r1 = mid
            else:
                l1 = mid + 1
        while l2 < r2:
            mid = (l2 + r2) >> 1
            if nums[mid] > target:
                r2 = mid
            else:
                l2 = mid + 1
        if l1 < l2: return [l1, l2 - 1]
        else: return [-1, -1]