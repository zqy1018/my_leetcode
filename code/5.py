class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        l = len(s)
        res, st, r = 0, 0, 0
        for i in range(l):
            cur = 0
            while 1:
                if i - cur < 0 or i + cur >= l or s[i - cur] != s[i + cur]:
                    cur -= 1
                    break
                cur += 1
            if cur * 2 + 1 > res:
                res = cur * 2 + 1
                st = i
                r = cur

            cur = 1
            while 1:
                if i - cur + 1 < 0 or i + cur >= l or s[i - cur + 1] != s[i + cur]:
                    cur -= 1
                    break
                cur += 1
            if cur * 2 > res:
                res = cur * 2
                st = i
                r = cur
        print(res, st, r)
        if res & 1:
            return s[st - r: st + r + 1]
        else:
            return s[st - r + 1: st + r + 1]
