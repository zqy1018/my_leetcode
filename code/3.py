class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        blist = [0 for i in range(128)]  # 布尔列表
        lst, res = 0, 0
        for i, ch in enumerate(s):
            idd = ord(ch)
            blist[idd] += 1
            if blist[idd] > 1:
                res = max(res, i - lst)
                while lst < i and blist[idd] > 1:
                    blist[ord(s[lst])] -= 1
                    lst += 1
        res = max(res, len(s) - lst)
        return res
