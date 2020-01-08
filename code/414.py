class Solution:
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        m1, m2, m3 = -3000000000, -3000000000, -3000000000
        for i in nums:
            if i > m1:
                m3, m2, m1 = m2, m1, i
            elif i > m2 and i < m1:
                m3, m2 = m2, i
            elif i > m3 and i < m2:
                m3 = i
        if m3 == -3000000000:
            return m1
        else:
            return m3
        