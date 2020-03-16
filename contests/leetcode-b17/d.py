class Solution:
    def distinctEchoSubstrings(self, text: str) -> int:
        l = len(text)
        ans = 0
        for i in range(1, l + 1):
            st = set()
            for j in range(2 * i - 1, l):
                ss = text[j - i + 1: j + 1]
                if text[j - 2 * i + 1: j - i + 1] == ss:
                    if ss not in st:
                        ans += 1
                        st.add(ss)
        return ans