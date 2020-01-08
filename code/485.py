class Solution:
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.append(0)
        cnt, ans, len1 = 0, 0, len(nums)
        for i in range(0, len1 + 1):
            if nums[i] == 1:
                cnt += 1
            else:
                ans = max(ans, cnt)
                cnt = 0
        return ans
