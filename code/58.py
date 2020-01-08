class Solution:
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        lst = s.split()
        if len(lst) == 0: return 0
        else: return lst[-1]