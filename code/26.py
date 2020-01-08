class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if nums == []: return 0
        len1, lst = len(nums), nums[0]
        i = 1
        while i < len1:
            if nums[i] == lst:
                nums.pop(i)
                i -= 1
                len1 -= 1
            else:
                lst = nums[i]
            i += 1
        return len1