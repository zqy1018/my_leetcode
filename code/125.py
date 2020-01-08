class Solution:
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        ss = []
        for i in s:
            if i.isalpha():
                ss.append(i.lower())
            elif i.isdigit():
                ss.append(i)
        return ss == ss[: : -1]
                