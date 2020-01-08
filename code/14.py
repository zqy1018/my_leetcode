class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if strs == []: return ""
        l, r = 0, 0
        for i in strs:
            r = max(r, len(i))
        while l < r:
            mid = (l + r + 1) >> 1
            s = strs[0][: l]
            flag = 1
            for i in strs[1: ]:
                if not i.startswith(s):
                    flag = 0
                    break
            if flag:
                l = mid
            else:
                r = mid - 1
        return strs[0][: l]