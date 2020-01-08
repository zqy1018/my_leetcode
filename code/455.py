class Solution:
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        g.sort()
        s.sort()
        ans, i, len1 = 0, 0, len(s)
        for j in g:
            while i < len1 and s[i] < j:
                i += 1
            if i == len1:
                break
            i += 1
            ans += 1
        return ans
