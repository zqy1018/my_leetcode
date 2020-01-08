class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        lst = [[] for i in range(26)]
        for i in range(len(s)):
            lst[ord(s[i]) - ord('a')].append(i)
        