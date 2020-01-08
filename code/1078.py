class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        lis = text.split()
        l = len(lis)
        return [lis[i + 2] for i in range(0, l - 2) if lis[i] == first and lis[i + 1] == second]