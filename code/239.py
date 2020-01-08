class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        que, len1, len2 = [], 0, len(nums)
        ans = []
        for i in range(k):
            while len1 > 0 and nums[i] >= que[-1][0]:
                que.pop()
                len1 -= 1
            que.append((nums[i], i))
            len1 += 1
        for i in range(k, len2):
            ans.append(que[0][0])
            if i - que[0][1] >= k:
                del que[0]
                len1 -= 1
            while len1 > 0 and nums[i] >= que[-1][0]:
                que.pop()
                len1 -= 1
            que.append((nums[i], i))
            len1 += 1
        ans.append(que[0][0])
        return ans
            