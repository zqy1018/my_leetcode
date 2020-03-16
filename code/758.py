class Solution:
    def boldWords(self, words: List[str], S: str) -> str:
        l = len(S)
        lis = [0] * l 
        for w in words:
            cur = 0
            
