class Solution:
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        n, cnt = len(nums), 0
        for i in range(0, n):
            if nums[i] == 0:
                nums.pop(i)
                n -= 1
                cnt += 1
            else:
                i += 1
        nums += [0] * cnt