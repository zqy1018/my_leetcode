class Solution:
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        def oord(x):
            return ord(x) - 97

        list1 = [0] * 26
        for i in s:
            list1[oord(i)] += 1

        for i in t:
            list1[oord(i)] -= 1
            if list1[oord(i)] < 0:
                return i