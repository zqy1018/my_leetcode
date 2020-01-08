class Solution:
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        def oord(x):
            return ord(x) - 97

        list1 = [0] * 26
        for i in magazine:
            list1[oord(i)] += 1

        for i in ransomNote:
            ch = oord(i)
            if list1[ch] == 0:
                return False
            list1[ch] -= 1
        return True