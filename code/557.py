class Solution:
    def reverseWords(self, s: str) -> str:
        lis = s.split()
        return " ".join(reversed([ss[: : -1] for ss in lis]))