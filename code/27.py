class Solution:
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        if nums == []: return 0
        len1, i = len(nums), 0
        while i < len1:
            if nums[i] == val:
                del nums[i]
                i -= 1
                len1 -= 1
            i += 1
        return len1