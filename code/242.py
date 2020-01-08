class Solution:
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t):
            return False
        list1 = [ord(i) for i in s]
        list2 = [ord(i) for i in t]
        list1.sort()
        list2.sort()
        return list1 == list2