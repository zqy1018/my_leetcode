class Solution:
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        P = ("a", "e", "i", "o", "u", "A", "E", "I", "O", "U")
        length = len(s)
        list1 = list(s)
        hd, tl = 0, length - 1
        while hd < tl:
            while hd < tl and list1[hd] not in P:
                hd += 1
            while hd < tl and list1[tl] not in P:
                tl -= 1
            if hd == tl:
                break
            list1[hd], list1[tl] = list1[tl], list1[hd]
            hd += 1
            tl -= 1
        return "".join(list1)