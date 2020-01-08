class Solution:
    def minAddToMakeValid(self, S):
        """
        :type S: str
        :rtype: int
        """
        l, r = 0, 0
        lst = list(S)
        for i in lst:
            if i == ')':
                if l:
                    l -= 1
                else:
                    r += 1
            else:
                l += 1
        return l + r
