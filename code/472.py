class Solution:
    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        l = len(words)
        lis = list(range(l))
        len_lis = [len(s) for s in words]
        lis.sort(key=lambda x: len_lis[x])

        ans = []
        st, st_l = set(), set()
        rg = range(1, l) if words[lis[0]] == "" else range(l)
        for i in rg:
            ll = len_lis[lis[i]]
            f = [False] * (ll + 1)
            f[0] = True
            for j in range(ll):
                for k in st_l:
                    if j + 1 >= k and f[j + 1 - k] and words[lis[i]][j + 1 - k: j + 1] in st:
                        f[j + 1] = True
                        break
            if f[ll]:
                ans.append(words[lis[i]])

            st.add(words[lis[i]])
            st_l.add(ll)
        
        return ans
