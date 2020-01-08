class Solution:
    def repeatedSubstringPattern(self, s):
        """
        :type s: str
        :rtype: bool
        """
        i, len1 = 2, len(s)
        if len1 == 1: return False
        if s == s[0] * len1: return True
        while i * i < len1:
            if len1 % i == 0:
                flag = 1
                for j in range(0, len1 - i, i):
                    if s[j: j + i] != s[j + i: j + i + i]:
                        flag = 0
                        break
                if flag: return True
                flag = 1
                t = len1 // i
                for j in range(0, len1 - t, t):
                    if s[j: j + t] != s[j + t: j + t + t]:
                        flag = 0
                        break
                if flag: return True
            i += 1
        if i * i == len1:
            flag = 1
            for j in range(0, len1 - i, i):
                if s[j: j + i] != s[j + i: j + i + i]:
                    flag = 0
                    break
            if flag: return True
        return False

        # 最快做法：利用循环移位
        # return s in (s + s)[1: -1]