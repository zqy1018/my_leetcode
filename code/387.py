class Solution:
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        def oord(x):
            return ord(x) - 97

        list1 = [0] * 26
        for i in s:
            list1[oord(i)] += 1
        
        for i, ch in enumerate(s):
            if list1[oord(ch)] == 1:
                return i
        return -1
