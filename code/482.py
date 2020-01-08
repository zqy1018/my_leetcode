class Solution:
    def licenseKeyFormatting(self, S, K):
        """
        :type S: str
        :type K: int
        :rtype: str
        """
        ans, cnt = [], 0
        for t in S[: : -1]:
            if t.isalpha() or t.isdigit():
                ans.append(t.upper())
                cnt += 1
                if cnt == K:
                    ans.append("-")
                    cnt = 0
        if ans == []: return ""
        if ans[-1] == "-":
            ans.pop(-1)
        return "".join(ans)[: : -1]