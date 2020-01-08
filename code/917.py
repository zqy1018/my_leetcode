class Solution:
    def reverseOnlyLetters(self, S):
        """
        :type S: str
        :rtype: str
        """
        if S == "": return S
        len1, list1 = len(S), list(S)
        i, j = 0, len1 - 1
        while i < j:
            while i < j and not list1[i].isalpha():
                i += 1
            while i < j and not list1[j].isalpha():
                j -= 1
            if i == j:
                break
            list1[i], list1[j] = list1[j], list1[i]
            i += 1
            j -= 1
        return "".join(list1)
            