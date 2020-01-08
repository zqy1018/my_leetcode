class Solution:
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        len1 = len(nums)
        if k == 0 or len1 == 1: 
            return
        a1, b1, a2, b2 = 0, len1 - 1 - k, len1 - k, len1 - 1
        # 均以下标为准
        while b2 - a2 != b1 - a1:
            if b2 - a2 > b1 - a1:
                len2 = (b1 - a1 + 1)
            else:
                len2 = (b2 - a2 + 1)
            for i in range(0, len2):
                nums[a1 + i], nums[b2 - len2 + 1 + i] = nums[b2 - len2 + 1 + i], nums[a1 + i]
            if b2 - a2 > b1 - a1:
                b2 -= len2
            else:
                a1 += len2
        len2 = b1 - a1 + 1
        for i in range(0, len2):
            nums[a1 + i], nums[a2 + i] = nums[a2 + i], nums[a1 + i]