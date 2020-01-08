class Solution:
    def isLongPressedName(self, name, typed):
        """
        :type name: str
        :type typed: str
        :rtype: bool
        """
        len1, len2 = len(name), len(typed)
        if len1 == 0 or len2 == 0:
            return len1 == 0 and len2 == 0
        lst1, j, lst2 = 0, 0, 0
        for i in range(0, len1):
            if name[i] != name[lst1]:
                while j < len2 and typed[j] == typed[lst2]:
                    j += 1
                if typed[lst2] != name[lst1] or j - lst2 < i - lst1:
                    return False
                lst1 = i
                lst2 = j
        while j < len2 and typed[j] == typed[lst2]:
            j += 1
        if j != len2 or typed[lst2] != name[lst1] or len2 - lst2 < len1 - lst1:
            return False
        return True