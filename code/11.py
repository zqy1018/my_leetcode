class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        len1 = len(height)
        h = list(zip(height, range(0, len1)))
        h.sort(key = lambda x: x[0])
        ans = 0
        hd, tl = 0, len1 - 1
        for i in h:
            hh, idx = i[0], i[1]
            ans = max(ans, max(idx - hd, tl - idx) * hh)
            height[idx] = -1
            while hd < tl and height[hd] == -1: hd += 1
            while hd < tl and height[tl] == -1: tl -= 1
        return ans