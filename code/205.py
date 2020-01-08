class Solution:
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        dict1 = {}
        set1 = set()
        for i, ch in enumerate(s, 0):
            to = dict1.get(ch)
            if to and to != t[i: i + 1]:
                return False
            elif not to:
                if t[i: i + 1] in set1:
                    return False
                else:
                    dict1[ch] = t[i: i + 1]
                    set1.add(t[i: i + 1])
        return True
