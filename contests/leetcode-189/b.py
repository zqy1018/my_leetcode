class Solution:
    def arrangeWords(self, text: str) -> str:
        s = text.split()
        s[0] = s[0].lower()
        n = len(s)
        lis = [(len(s[i]), i) for i in range(n)]
        lis.sort()
        ans = []
        
        ans.append(s[lis[0][1]].title())
        for i in range(1, n):
            ans.append(s[lis[i][1]])
        return " ".join(ans)