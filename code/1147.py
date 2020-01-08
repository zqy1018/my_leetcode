class Solution:
    def longestDecomposition(self, text: str) -> int:
        len1 = len(text) // 2
        for i in range(1, len1 + 1):
            if text[0: i] == text[-i: ]:
                return self.longestDecomposition(text[i: -i]) + 1
        return 1