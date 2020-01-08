class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans, j, cnt1, cnt2 = 0, 1, 0, 0
        for i in range(0, 32):
            for t in nums:
                if t >= 0:
                    if t & j:
                        cnt1 += 1
                else:
                    if (-t) & j:
                        cnt2 += 1
            if cnt1 % 3 == 1:
                ans += j
            elif cnt2 % 3 == 1:
                ans += -j
            j <<= 1
            cnt1, cnt2 = 0, 0
        return ans