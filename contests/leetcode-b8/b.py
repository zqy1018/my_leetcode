class Solution:
    def beforeAndAfterPuzzles(self, phrases: List[str]) -> List[str]:
        l = len(phrases)
        lis = [s.split() for s in phrases]
        st = set()
        for i in range(0, l):
            for j in range(0, l):
                if i == j: 
                    continue
                if lis[i][-1] == lis[j][0]:
                    b = " ".join(lis[i] + lis[j][1: ])
                    st.add(b)
        stl = list(st)
        stl.sort()
        return stl