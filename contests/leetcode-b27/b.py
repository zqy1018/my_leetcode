class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        l = len(s)
        st = set()
        if l - k + 1 < (2 ** k): 
            return False
        for i in range(l - k + 1):
            st.add(s[i: i + k])
        return len(s) == 2 ** k