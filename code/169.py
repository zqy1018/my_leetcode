class Solution:
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans, cnt = 0, 1
        for i in nums:
            if i != ans:
                if cnt == 1:
                    ans = i
                else:
                    cnt -= 1
            else:
                cnt += 1
        return ans
        