class Solution:
    def maximumProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        m1, m2, m3, a1, a2 = -3000000000, -3000000000, -3000000000, 3000000000, 3000000000
        for i in nums:
            if i > m1:
                m1, m2, m3 = i, m1, m2
            elif i > m2:
                m2, m3 = i, m2
            elif i > m3:
                m3 = i
            if i < a1:
                a1, a2 = i, a1
            elif i < a2:
                a2 = i
        ans = max(m1 * m2 * m3, m1 * a1 * a2)
        return ans
